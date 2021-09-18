/// Source : https://leetcode.com/problems/maximum-earnings-from-taxi/
/// Author : liuyubobobo
/// Time   : 2021-09-18

#include <iostream>
#include <vector>

using namespace std;


/// Sorting + DP + Binary Search
/// Time Complexity: O(mlogm + nlogm + m)
/// Space Complexity: O(n)
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        sort(rides.begin(), rides.end());
        vector<long long> dp(n + 2, 0ll);
        for(int i = n; i >= 1; i --){
            dp[i] = dp[i + 1];
            vector<int> t = {i, i, 0};
            vector<vector<int>>::iterator iter = lower_bound(rides.begin(), rides.end(), t);
            while(iter != rides.end() && (*iter)[0] == i){
                dp[i] = max(dp[i], (*iter)[1] - (*iter)[0] + (*iter)[2] + dp[(*iter)[1]]);
                iter ++;
            }
        }
        return dp[1];
    }
};


int main() {

    return 0;
}
