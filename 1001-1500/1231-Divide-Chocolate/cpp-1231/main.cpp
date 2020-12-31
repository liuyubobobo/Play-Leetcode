/// Source : https://leetcode.com/problems/divide-chocolate/
/// Author : liuyubobobo
/// Time   : 2019-10-20

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(n * log(10^9))
/// Spaace Complexity: O(1)
class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {

        int l = 0, r = 1e9;
        while(l < r){
            int mid = l + (r - l + 1) / 2;
            if(ok(sweetness, K + 1, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

private:
    int ok(const vector<int>& sweetness, int K, int sum){

        int n = 0, cur = 0;
        for(int e: sweetness){
            if(cur < sum) cur += e;
            else n ++, cur = e;
        }
        if(cur >= sum) n ++;
        return n >= K;
    }
};


int main() {

    vector<int> sweetness1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << Solution().maximizeSweetness(sweetness1, 5) << endl;
    // 6

    vector<int> sweetness2 = {5,6,7,8,9,1,2,3,4};
    cout << Solution().maximizeSweetness(sweetness2, 8) << endl;
    // 1

    vector<int> sweetness3 = {1,2,2,1,2,2,1,2,2};
    cout << Solution().maximizeSweetness(sweetness3, 2) << endl;
    // 5

    return 0;
}