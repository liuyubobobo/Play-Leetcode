/// Source : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
/// Author : liuyubobobo
/// Time   : 2019-03-16

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlog(sum(weights)))
/// Space Complexity: O(1)
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {

        int l = *max_element(weights.begin(), weights.end()),
            r = accumulate(weights.begin(), weights.end(), 0);
        while(l < r){
//            cout << "check " << l << " " << r <<  endl;
            int mid = (l + r) / 2;
            if(ok(weights, mid, D))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

private:
    bool ok(const vector<int>& weights, int C, int D){

        int d = 0, cur = 0;
        for(int w: weights)
            if(cur + w <= C) cur += w;
            else d ++, cur = w;
        if(cur) d ++;
        return d <= D;
    }
};


int main() {

    vector<int> weight1 = {1,2,3,4,5,6,7,8,9,10};
    cout << Solution().shipWithinDays(weight1, 5) << endl;
    // 15

    vector<int> weight2 = {1,2,3,1,1};
    cout << Solution().shipWithinDays(weight2, 4) << endl;
    // 3

    return 0;
}