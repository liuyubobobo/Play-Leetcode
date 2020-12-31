/// Source : https://leetcode.com/problems/ones-and-zeroes/description/
/// Author : liuyubobobo
/// Time   : 2018-08-13

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/// 0-1 backsack problem
/// Dynamic Programming
/// Time Complexity: O(sizeof(array)*m*n)
/// Space Complexity: O(sizeof(array)*m*n)
class Solution {

public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<int> mcost(strs.size(), 0), ncost(strs.size(), 0);
        for(int i = 0 ; i < strs.size() ; i ++)
            for(char c: strs[i])
                if(c == '0')
                    mcost[i] ++;
                else
                    ncost[i] ++;

        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for(int u = mcost[0]; u <= m ; u ++)
            for(int v = ncost[0] ; v <= n ; v ++)
                dp[0][u][v] = 1;

        for(int i = 1 ; i < strs.size() ; i ++)
            for(int u = 0 ; u <= m ; u ++)
                for(int v = 0 ; v <= n ; v ++){
                    dp[i][u][v] = dp[i - 1][u][v];
                    if(u >= mcost[i] && v >= ncost[i])
                        dp[i][u][v] = max(dp[i][u][v], 1 + dp[i - 1][u - mcost[i]][v - ncost[i]]);
                }

        return dp[strs.size() - 1][m][n];
    }
};


int main() {

    vector<string> vec1 = {"10", "001", "111001", "1", "0"};
    int m1 = 5;
    int n1 = 3;
    cout << Solution().findMaxForm(vec1, m1, n1) << endl;

    vector<string> vec2 = {"10", "0", "1"};
    int m2 = 1;
    int n2 = 1;
    cout << Solution().findMaxForm(vec2, m2, n2) << endl;

    return 0;
}