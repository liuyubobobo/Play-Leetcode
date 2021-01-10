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

        vector<vector<int>> dp(k, vector<int>(1 << n, -1));
        return dfs(n, t, (1 << n) - 1, k - 1, dp);
    }

private:
    int dfs(int n, const vector<int>& t, int state, int k,
            vector<vector<int>>& dp){

        if(k == 0) return state == 0 ? INT_MAX : t[state];
        if(state == 0) return INT_MAX;
        if(dp[k][state] != -1) return dp[k][state];

        int res = INT_MAX;
        for (int s = state; s; s = (s - 1) & state)
            if(s != state){
                res = min(res, max(t[s], dfs(n, t, state - s, k - 1, dp)));
            }
        return dp[k][state] = res;
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
