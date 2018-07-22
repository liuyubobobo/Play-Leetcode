/// Source : https://leetcode.com/problems/koko-eating-bananas/description/
/// Author : liuyubobobo
/// Time   : 2018-07-21

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlog(maxpile))
/// Space Complexity: O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {

        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l < r){
            int mid = (l + r) / 2;
            if(ok(piles, mid, H))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

private:
    bool ok(const vector<int>& piles, int K, int H){

        int T = 0;
        for(int pile: piles)
            T += pile / K + (pile % K == 0 ? 0 : 1);
        return T <= H;
    }
};


int main() {

    vector<int> piles1 = {3, 6, 7, 11};
    int H1 = 8;
    cout << Solution().minEatingSpeed(piles1, H1) << endl;
    // 4

    vector<int> piles2 = {30, 11, 23, 4, 20};
    int H2 = 5;
    cout << Solution().minEatingSpeed(piles2, H2) << endl;
    // 30

    vector<int> piles3 = {30, 11, 23, 4, 20};
    int H3 = 6;
    cout << Solution().minEatingSpeed(piles3, H3) << endl;
    // 23

    return 0;
}