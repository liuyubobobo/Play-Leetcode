/// Source : https://leetcode.com/problems/palindromic-substrings/
/// Author : liuyubobobo
/// Time   : 2021-03-27

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int countSubstrings(string s) {

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size() + 1, true));

        int res = s.size();
        for(int len = 2; len <= s.size(); len ++)
            for(int i = 0; i + len <= s.size(); i ++)
                if(s[i] == s[i + len - 1] && dp[i + 1][len - 2])
                    res ++;
                else dp[i][len] = false;
        return res;
    }
};


int main() {

    return 0;
}
