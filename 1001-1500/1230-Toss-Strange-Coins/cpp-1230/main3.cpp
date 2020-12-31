/// Source : https://leetcode.com/problems/toss-strange-coins/
/// Author : liuyubobobo
/// Time   : 2019-10-19

#include <iostream>
#include <vector>

using namespace std;


/// Dynamaic Programming with Space Optimization
/// Time Complexity: O(|prob| * target)
/// Space Complexity: O(target)
class Solution {

public:
    double probabilityOfHeads(vector<double>& prob, int target) {

        int n = prob.size();
        vector<double> dp(target + 1, 0.0);

        if(target) dp[1] = prob[0];
        dp[0] = 1.0 - prob[0];
        for(int i = 1; i < n; i ++){
            for(int j = target; j >= 1; j --)
                dp[j] = dp[j] * (1 - prob[i]) + dp[j - 1] * prob[i];
            dp[0] = dp[0] * (1 - prob[i]);
        }
        return dp[target];
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