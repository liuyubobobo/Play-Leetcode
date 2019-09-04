/// Source : https://leetcode.com/problems/decode-ways/
/// Author : liuyubobobo
/// Time   : 2019-09-03

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int numDecodings(string s) {

        int n = s.size();
        if(n == 1 || s[0] == '0') return s[0] != '0';

        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for(int i = n - 1; i >= 0; i --)
            if(s[i] != '0'){
                dp[i] = dp[i + 1];
                if(i + 1 < n && s.substr(i, 2) <= "26") dp[i] += dp[i + 2];
            }

        return dp[0];
    }
};


int main() {

    cout << Solution().numDecodings("12") << endl;  // 2
    cout << Solution().numDecodings("226") << endl; // 3
    cout << Solution().numDecodings("101") << endl; // 1
    cout << Solution().numDecodings("301") << endl; // 0

    return 0;
}