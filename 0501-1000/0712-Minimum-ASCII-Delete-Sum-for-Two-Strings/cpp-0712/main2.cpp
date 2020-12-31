/// Source : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
/// Author : liuyubobobo
/// Time   : 2017-10-21

#include <iostream>
#include <string>

using namespace std;

/// Dynamic Programming
/// calculate the max ASCII sum of common sequence
///
/// Time Complexity: O(len(s1) * len(s2))
/// Space Complexity:  O(len(s1) * len(s2))
class Solution {

private:
    int dp[1001][1001];

public:
    int minimumDeleteSum(string s1, string s2) {

        for(int i = 0 ; i <= s1.size() ; i ++)
            dp[i][s2.size()] = 0;

        for(int j = 0 ; j <= s2.size() ; j ++)
            dp[s1.size()][j] = 0;

        for(int i = s1.size() - 1 ; i >= 0 ; i --)
            for(int j = s2.size() - 1 ; j >= 0 ; j --){
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                if(s1[i] == s2[j])
                    dp[i][j] = max(dp[i][j], s1[i] + dp[i+1][j+1]);
            }

        int ascSum1 = ascSum(s1);
        int ascSum2 = ascSum(s2);

        return ascSum1 + ascSum2 - 2*dp[0][0];
    }

private:
    int ascSum(const string& s){

        int total = 0;
        for(int i = 0 ; i < s.size() ; i ++)
            total += (int)s[i];
        return total;
    }
};

int main() {

    cout << Solution().minimumDeleteSum("sea", "eat") << endl;
    cout << Solution().minimumDeleteSum("delete", "leet") << endl;

    return 0;
}