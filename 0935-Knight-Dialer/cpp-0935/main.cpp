/// Source : https://leetcode.com/problems/knight-dialer/
/// Author : liuyubobobo
/// Time   : 2018-11-03

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(10 * N)
/// Space Complexity: O(10 * N)
class Solution {

private:
    int MOD = 1e9 + 7;
    const vector<vector<int>> trans = {
            {4, 6}, // 0
            {6, 8}, // 1
            {7, 9}, // 2
            {4, 8}, // 3
            {3, 9, 0}, // 4
            {}, // 5
            {1, 7, 0}, // 6
            {2, 6}, // 7
            {1, 3}, // 8
            {2, 4}  // 9
    };

public:
    int knightDialer(int N) {

        if(N == 1)
            return 10;

        vector<vector<int>> dp(N, vector<int>(10, -1));
        int res = 0;
        for(int i = 0; i < 10; i ++)
            if(i != 5){
                res += dfs(i, N - 1, dp);
                res %= MOD;
            }
        return res;
    }

private:
    int dfs(int start, int step, vector<vector<int>>& dp){

        if(step == 0)
            return 1;

        if(dp[step][start] != -1)
            return dp[step][start];

        int res = 0;
        for(int i = 0; i < trans[start].size(); i ++){
            res += dfs(trans[start][i], step - 1, dp);
            res %= MOD;
        }
        return dp[step][start] = res;
    }
};


int main() {

    cout << Solution().knightDialer(1) << endl;
    // 10

    cout << Solution().knightDialer(2) << endl;
    // 20

    cout << Solution().knightDialer(3) << endl;
    // 46

    cout << Solution().knightDialer(4) << endl;
    // 104

    cout << Solution().knightDialer(18) << endl;
    // 11208704

    return 0;
}