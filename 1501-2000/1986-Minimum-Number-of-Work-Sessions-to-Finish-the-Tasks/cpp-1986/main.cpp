/// Source : https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/
/// Author : liuyubobobo
/// Time   : 2021-08-28

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n^2 * 2^n)
/// Space Complexity: O(n * 2^n)
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {

        int n = tasks.size();
        vector<vector<int>> dp(sessionTime + 1, vector<int>(1 << n, -1));

        return 1 + dfs(n, tasks, sessionTime, sessionTime, (1 << n) - 1, dp);
    }

private:
    int dfs(int n, vector<int>& tasks, int sessionTime,
            int left, int state, vector<vector<int>>& dp){

        if(state == 0) return 0;
        if(dp[left][state] != -1) return dp[left][state];

        int res = INT_MAX;
        for(int i = 0; i < n; i ++)
            if((1 << i) & state){
                if(left >= tasks[i])
                    res = min(res, dfs(n, tasks, sessionTime, left - tasks[i], state - (1 << i), dp));
                else
                    res = min(res, 1 + dfs(n, tasks, sessionTime, sessionTime - tasks[i], state - (1 << i), dp));
            }
        return dp[left][state] = res;
    }
};


int main() {

    vector<int> task1 = {1, 2, 3};
    cout << Solution().minSessions(task1, 3) << endl;
    // 2

    vector<int> task2 = {3, 1, 3, 1, 1};
    cout << Solution().minSessions(task2, 8) << endl;
    // 2

    vector<int> task3 = {1, 2, 3, 4, 5};
    cout << Solution().minSessions(task3, 15) << endl;
    // 1

    return 0;
}
