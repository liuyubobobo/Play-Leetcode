/// Source : https://leetcode.com/problems/valid-palindrome-iii/
/// Author : liuyubobobo
/// Time   : 2019-10-06

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(|s|^2)
/// Space Complexity: O(|s|^2)
class Solution {
public:
    bool isValidPalindrome(string s, int k) {

        vector<vector<int>> dp(s.size(), vector<int>(s.size() + 1, 0));
        for(int i = 0; i + 1 < s.size(); i ++)
            dp[i][2] = (s[i] == s[i + 1] ? 0 : 1);

        for(int len = 3; len <= s.size(); len ++)
            for(int i = 0; i + len <= s.size(); i ++){
                dp[i][len] = 1 + min(dp[i][len - 1], dp[i + 1][len - 1]);
                if(s[i] == s[i + len - 1])
                    dp[i][len] = min(dp[i][len], dp[i + 1][len - 2]);
            }
        return dp[0][s.size()] <= k;
    }
};


int main() {

    cout << Solution().isValidPalindrome("abcdeca", 2) << endl;

    return 0;
}