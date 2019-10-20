/// Source : https://leetcode.com/problems/toss-strange-coins/
/// Author : liuyubobobo
/// Time   : 2019-10-19

#include <iostream>
#include <vector>

using namespace std;


/// Dynamaic Programming
/// Time Complexity: O(|prob| * target)
/// Space Complexity: O(|prob| * target)
class Solution {

public:
    double probabilityOfHeads(vector<double>& prob, int target) {

        int n = prob.size();
        vector<vector<double>> dp(n, vector<double>(target + 1, 0.0));
        if(target) dp[0][1] = prob[0];
        dp[0][0] = 1.0 - prob[0];
        for(int i = 1; i < n; i ++){
            dp[i][0] = dp[i - 1][0] * (1 - prob[i]);
            for(int j = 1; j <= target; j ++)
                dp[i][j] = dp[i - 1][j] * (1 - prob[i]) + dp[i - 1][j - 1] * prob[i];
        }
        return dp[n - 1][target];
    }
};


int main() {

    vector<double> prob1 = {0.4};
    cout << Solution().probabilityOfHeads(prob1, 1) << endl;
    // 0.4

    vector<double> prob2 = {0.5,0.5,0.5,0.5,0.5};
    cout << Solution().probabilityOfHeads(prob2, 0) << endl;
    // 0.03125

    return 0;
}