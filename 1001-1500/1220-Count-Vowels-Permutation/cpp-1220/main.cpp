/// Source : https://leetcode.com/problems/count-vowels-permutation/
/// Author : liuyubobobo
/// Time   : 2019-10-05

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int MOD = 1e9 + 7;
    vector<vector<int>> g = {
            //a  e  i  o  u
            {0, 1, 0, 0, 0}, // a
            {1, 0, 1, 0, 0}, // e
            {1, 1, 0, 1, 1}, // i
            {0, 0, 1, 0, 1}, // o
            {1, 0, 0, 0, 0} // u
    };

public:
    int countVowelPermutation(int n) {

        vector<vector<int>> dp(5, vector<int>(n, -1));
        int res = 0;
        for(int i = 0; i < 5; i ++)
            res += dfs(i, n - 1, dp), res %= MOD;
        return res;
    }

private:
    int dfs(int cur, int left, vector<vector<int>>& dp){

        if(!left) return 1;
        if(dp[cur][left] != -1) return dp[cur][left];

        int res = 0;
        for(int i = 0; i < 5; i ++)
            if(g[cur][i])
                res += dfs(i, left - 1, dp), res %= MOD;
        return dp[cur][left] = res;
    }
};


int main() {

    cout << Solution().countVowelPermutation(1) << endl;
    // 5

    cout << Solution().countVowelPermutation(2) << endl;
    // 10

    cout << Solution().countVowelPermutation(5) << endl;
    // 68

    return 0;
}