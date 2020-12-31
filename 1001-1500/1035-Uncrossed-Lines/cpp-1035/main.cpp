/// Source : https://leetcode.com/problems/uncrossed-lines/
/// Author : liuyubobobo
/// Time   : 2019-04-27

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Memory Search
/// Time Complexity: O(|A| * |B|)
/// Space Complexity: O(|A| * |B|)
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {

        unordered_map<int, vector<int>> Apos, Bpos;
        for(int i = 0; i < A.size(); i ++)
            Apos[A[i]].push_back(i);
        for(int i = 0; i < B.size(); i ++)
            Bpos[B[i]].push_back(i);

        vector<vector<int>> dp(A.size(), vector<int>(B.size(), -1));
        return dfs(A, B, 0, 0, Apos, Bpos, dp);
    }

private:
    int dfs(const vector<int>& A, const vector<int>& B, int ai, int bj,
            unordered_map<int, vector<int>>& Apos,
            unordered_map<int, vector<int>>& Bpos,
            vector<vector<int>>& dp){

        if(ai >= A.size() || bj >= B.size())
            return 0;

        if(dp[ai][bj] != -1) return dp[ai][bj];

        int res = dfs(A, B, ai + 1, bj, Apos, Bpos, dp);
        for(int j: Bpos[A[ai]])
            if(j >= bj)
                res = max(res, 1 + dfs(A, B, ai + 1, j + 1, Apos, Bpos, dp));

        return dp[ai][bj] = res;
    }
};


int main() {

    vector<int> A1 = {3};
    vector<int> B1 = {3, 3, 2};
    cout << Solution().maxUncrossedLines(A1, B1) << endl;
    // 1

    return 0;
}