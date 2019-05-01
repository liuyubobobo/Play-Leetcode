/// Source : https://leetcode.com/problems/uncrossed-lines/
/// Author : liuyubobobo
/// Time   : 2019-04-30

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Memory Search
/// It's actualy The Longest Common Subsequence Problem
///
/// Time Complexity: O(|A| * |B|)
/// Space Complexity: O(|A| * |B|)
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {

        vector<vector<int>> dp(A.size(), vector<int>(B.size(), -1));
        return dfs(A, B, 0, 0, dp);
    }

private:
    int dfs(const vector<int>& A, const vector<int>& B, int ai, int bj,
            vector<vector<int>>& dp){

        if(ai >= A.size() || bj >= B.size())
            return 0;

        if(dp[ai][bj] != -1) return dp[ai][bj];

        int res = dfs(A, B, ai + 1, bj, dp);
        for(int j = bj; j < B.size(); j ++)
            if(A[ai] == B[j])
                res = max(res, 1 + dfs(A, B, ai + 1, j + 1, dp));

        return dp[ai][bj] = res;
    }
};


int main() {

    vector<int> A1 = {3};
    vector<int> B1 = {3, 3, 2};
    cout << Solution().maxUncrossedLines(A1, B1) << endl;
    // 1

    vector<int> A2 = {2, 5, 1, 2, 5};
    vector<int> B2 = {10, 5, 2, 1, 5, 2};
    cout << Solution().maxUncrossedLines(A2, B2) << endl;
    // 3

    return 0;
}