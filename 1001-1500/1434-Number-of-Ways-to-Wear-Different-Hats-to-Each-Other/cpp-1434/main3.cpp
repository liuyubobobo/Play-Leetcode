/// Source : https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>

using namespace std;


/// State Compression + DP
/// Space Optimized
/// Time Complexity: O(n * 40 * (1 << n))
/// Space Complexity: O(n + (1 << n))
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int numberWays(vector<vector<int>>& hats) {

        int n = hats.size();
        for(vector<int>& v: hats) for(int& e: v) e --;

        vector<vector<int>> g(40, vector<int>());
        for(int i = 0; i < hats.size(); i ++)
            for(int hat: hats[i]) g[hat].push_back(i);

        vector<vector<int>> dp(2, vector<int>(1 << n, 0));
        dp[0][0] = 1;
        for(int e: g[0]) dp[0][1 << e] = 1;
        for(int index = 1; index < 40; index ++)
            for(int state = 0; state < (1 << n); state ++){
                dp[index & 1][state] = dp[(index - 1) & 1][state];
                for(int e: g[index])
                    if((1 << e) & state){
                        dp[index & 1][state] += dp[(index - 1) & 1][state - (1 << e)];
                        dp[index & 1][state] %= MOD;
                    }
            }
        return dp[1][(1 << n) - 1];
    }
};


int main() {

    vector<vector<int>> hats1 = {{3,4},{4,5},{5}};
    cout << Solution().numberWays(hats1) << endl;
    // 1

    vector<vector<int>> hats2 = {{3,5, 1},{3,5}};
    cout << Solution().numberWays(hats2) << endl;
    // 4

    return 0;
}
