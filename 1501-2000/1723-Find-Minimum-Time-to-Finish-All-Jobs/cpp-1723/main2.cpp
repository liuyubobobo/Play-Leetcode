/// Source : https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
/// Author : liuyubobobo
/// Time   : 2021-01-09

#include <iostream>
#include <vector>

using namespace std;


/// State Compression Memory Search
/// Time Complexity: O(k * 2^n)
/// Space Complexity: O(k * 2^n)
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {

        int n = jobs.size();
        vector<int> t(1 << n, 0);
        for(int state = 1; state < (1 << n); state ++)
            t[state] = jobs[__builtin_ctz(state)] + t[state - (1 << __builtin_ctz(state))];

        vector<vector<int>> dp(k, vector<int>(1 << n, INT_MAX));
        for(int state = 0; state < (1 << n); state ++)
            dp[0][state] = t[state];

        for(int i = 1; i < k; i ++)
            for(int state = 1; state < (1 << n); state ++){
                for (int s = state; s; s = (s - 1) & state)
                    dp[i][state] = min(dp[i][state], max(t[s], dp[i - 1][state - s]));
            }
        return dp[k - 1][(1 << n) - 1];
    }
};


int main() {

    vector<int> jobs1 = {3, 2, 3};
    cout << Solution().minimumTimeRequired(jobs1, 3) << endl;
    // 3

    vector<int> jobs2 = {1, 2, 4, 7, 8};
    cout << Solution().minimumTimeRequired(jobs2, 2) << endl;
    // 11

    return 0;
}
