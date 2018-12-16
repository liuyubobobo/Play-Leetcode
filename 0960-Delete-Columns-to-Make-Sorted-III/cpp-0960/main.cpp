/// Source : https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
/// Author : liuyubobobo
/// Time   : 2018-12-15

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(m * n * n)
/// Space Complexity: O(m * n)
class Solution {

private:
    int m, n;

public:
    int minDeletionSize(vector<string>& A) {

        for(string& s: A)
            s = "a" + s;
        m = A.size();
        n = A[0].size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(A, 0, 0, dp);
    }

private:
    int dfs(const vector<string>& A, int index, int prev,
            vector<vector<int>>& dp){

        if(index == n)
            return 0;

        if(dp[index][prev] != -1)
            return dp[index][prev];

        int res = 1 + dfs(A, index + 1, prev, dp);

        bool ok = true;
        for(int i = 0; i < m; i ++)
            if(A[i][index] < A[i][prev]){
                ok = false;
                break;
            }
        if(ok)
            res = min(res, dfs(A, index + 1, index, dp));

        return dp[index][prev] = res;
    }
};


int main() {

    vector<string> A1 = {"babca","bbazb"};
    cout << Solution().minDeletionSize(A1) << endl;

    return 0;
}