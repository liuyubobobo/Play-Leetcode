/// Source : https://leetcode.com/problems/ones-and-zeroes/description/
/// Author : liuyubobobo
/// Time   : 2018-08-13

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/// 0-1 backsack problem
/// Recursion Implimentation (Memory Search)
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

        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return findMaxForm(strs.size() - 1, m, n, dp, mcost, ncost);
    }

private:
    int findMaxForm(int k, int m, int n, vector<vector<vector<int>>>& dp,
                    const vector<int>& mcost, const vector<int>& ncost){

        if(k < 0)
            return 0;

        if(dp[k][m][n] != -1)
            return dp[k][m][n];

        dp[k][m][n] = findMaxForm(k - 1, m, n, dp, mcost, ncost);
        if(m >= mcost[k] && n >= ncost[k])
            dp[k][m][n] = max(1 + findMaxForm(k - 1, m - mcost[k], n - ncost[k], dp, mcost, ncost),
                              dp[k][m][n]);

        return dp[k][m][n];
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