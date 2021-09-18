/// Source : https://leetcode.com/problems/maximum-earnings-from-taxi/
/// Author : liuyubobobo
/// Time   : 2021-09-18

#include <iostream>
#include <vector>

using namespace std;


/// Sorting + DP (No Binary Search)
/// Time Complexity: O(mlogm + n + m)
/// Space Complexity: O(n)
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        sort(rides.begin(), rides.end());
        int j = rides.size() - 1;

        vector<long long> dp(n + 2, 0ll);
        for(int i = n; i >= 1; i --){
            dp[i] = dp[i + 1];
            while(j >= 0 && rides[j][0] == i){
                dp[i] = max(dp[i], rides[j][1] - rides[j][0] + rides[j][2] + dp[rides[j][1]]);
                j --;
            }
        }
        return dp[1];
    }
};


int main() {

    return 0;
}
