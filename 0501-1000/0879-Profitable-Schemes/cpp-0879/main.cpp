/// Source : https://leetcode.com/problems/profitable-schemes/description/
/// Author : liuyubobobo
/// Time   : 2018-08-04
#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(G * P * n)
/// Space Complexity: O(G * P)
class Solution {

private:
    int MOD = 1e9 + 7;

public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {

        //vector<vector<vector<int>>> dp(2, vector<vector<int>>(G + 1, vector<int>(P + 1, -1)));
        vector<vector<int>> dp(P + 1, vector<int>(G + 1, 0));
        dp[0][0] = 1;
        for(int i = 0; i < group.size() ; i ++){

            for(int j = P; j >= 0; j --)
                for(int k = G - group[i]; k >= 0; k --){
                    int p = min(P, j + profit[i]);
                    int g = k + group[i];
                    dp[p][g] += dp[j][k];
                    dp[p][g] %= MOD;
                }
        }

        long long res = 0ll;
        for(int x: dp[P]){
            res += x;
            res %= MOD;
        }
        return res;
    }
};


int main() {

    int G1 = 5, P1 = 3;
    vector<int> group1 = {2, 2};
    vector<int> profit1 = {2, 3};
    cout << Solution().profitableSchemes(G1, P1, group1, profit1) << endl; // 2

    int G2 = 10, P2 = 5;
    vector<int> group2 = {2, 3, 5};
    vector<int> profit2 = {6, 7, 8};
    cout << Solution().profitableSchemes(G2, P2, group2, profit2) << endl; // 7

    return 0;
}