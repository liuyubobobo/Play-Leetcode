/// Source : https://leetcode.com/problems/ones-and-zeroes/description/
/// Author : liuyubobobo
/// Time   : 2018-08-13

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/// Dynamic Programming with space optimization
/// Time Complexity: O(sizeof(array)*m*n)
/// Space Complexity: O(m*n)
class Solution {

public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> dp(m + 1 , vector<int>(n + 1, 0));
        for(int i = 0 ; i < strs.size() ; i ++){
            int mcost = 0, ncost = 0;
            for(char c: strs[i])
                if(c == '0')
                    mcost ++;
                else
                    ncost ++;

            for(int u = m ; u >= mcost ; u --)
                for(int v = n ; v >= ncost ; v --)
                    dp[u][v] = max(dp[u][v] , 1 + dp[u - mcost][v - ncost]);
        }
        return dp[m][n];
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