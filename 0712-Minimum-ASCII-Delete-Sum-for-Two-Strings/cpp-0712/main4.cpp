/// Source : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
/// Author : liuyubobobo
/// Time   : 2017-10-22

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// calculate the minimum delete ASCII sum for common sequence
///
/// Time Complexity: O(len(s1) * len(s2))
/// Space Complexity:  O(len(s1) * len(s2))
class Solution {

public:
    int minimumDeleteSum(string s1, string s2) {

        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));

        for(int i = s1.size()-1 ; i >= 0 ; i --)
            dp[i][s2.size()] = s1[i] + dp[i+1][s2.size()];

        for(int j = s2.size()-1 ; j >= 0 ; j --)
            dp[s1.size()][j] = s2[j] + dp[s1.size()][j+1];

        for(int i = s1.size()-1 ; i >= 0 ; i --)
            for(int j = s2.size()-1 ; j >= 0 ; j --){
                dp[i][j] = min(s1[i] + dp[i+1][j], s2[j] + dp[i][j+1]);
                if(s1[i] == s2[j])
                    dp[i][j] = min(dp[i][j], dp[i+1][j+1]);
            }

        return dp[0][0];
    }
};

int main() {

    cout << Solution().minimumDeleteSum("sea", "eat") << endl;
    cout << Solution().minimumDeleteSum("delete", "leet") << endl;

    return 0;
}