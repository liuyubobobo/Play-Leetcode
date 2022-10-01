/// Source : https://leetcode-cn.com/problems/UlBDOe/
/// Author : liuyubobobo
/// Time   : 2020-09-12

#include <iostream>
#include <vector>

using namespace std;


/// DP - Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int n;
    const int INF = 1e9;

public:
    int minimumOperations(string leaves) {

        n = leaves.size();
        vector<vector<int>> dp(3, vector<int>(n, -1));
        // 0: ryr, 1: yr, 2: r
        return dfs(leaves, 0, 0, dp);
    }

private:
    int dfs(const string& s, int mod, int index, vector<vector<int>>& dp){

        if(index == n - 1){
            if(mod != 2) return INF;
            return s[index] == 'r' ? 0 : 1;
        }
        if(dp[mod][index] != -1) return dp[mod][index];

        int res = 0;
        if(mod == 0){
            int op = s[index] == 'r' ? 0 : 1;
            res = op + dfs(s, 0, index + 1, dp);
            res = min(res, op + dfs(s, 1, index + 1, dp));
        }
        else if(mod == 1){
            int op = s[index] == 'r' ? 1 : 0;
            res = op + dfs(s, 1, index + 1, dp);
            res = min(res, op + dfs(s, 2, index + 1, dp));
        }
        else{
            int op = s[index] == 'r' ? 0 : 1;
            res = op + dfs(s, 2, index + 1, dp);
        }
        return dp[mod][index] = res;
    }
};

int main() {

    cout << Solution().minimumOperations("rrryyyrryyyrr") << endl;
    // 2

    cout << Solution().minimumOperations("ryr") << endl;
    // 0

    return 0;
}
