/// Source : https://leetcode.com/problems/solving-questions-with-brainpower/
/// Author : liuyubobobo
/// Time   : 2022-01-15

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    long long mostPoints(vector<vector<int>>& questions) {

        int n = questions.size();
        vector<long long> dp(n, -1);
        return dfs(n, questions, 0, dp);
    }

private:
    long long dfs(int n, const vector<vector<int>>& questions, int index,
                  vector<long long>& dp){

        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];

        long long res = dfs(n, questions, index + 1, dp);
        res = max(res, (long long)questions[index][0] + dfs(n, questions, index + questions[index][1] + 1, dp));
        return dp[index] = res;
    }
};


int main() {

    vector<vector<int>> q1 = {{3,2},{4,3},{4,4},{2,5}};
    cout << Solution().mostPoints(q1) << endl;
    // 5

    vector<vector<int>> q2 = {{1,1},{2,2},{3, 3}, {4,4},{5,5}};
    cout << Solution().mostPoints(q2) << endl;
    // 7

    return 0;
}
