/// Source : https://leetcode.com/problems/longest-ideal-subsequence/
/// Author : liuyubobobo
/// Time   : 2022-08-10

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int longestIdealString(string s, int k) {

        vector<int> dp(26, 0);
        for(char c: s){
            int res = 0;
            for(char end = max(c - k, (int)'a'); end <= min(c + k, (int)'z'); end ++)
                res = max(res, dp[end - 'a'] + 1);
            dp[c - 'a'] = max(dp[c - 'a'], res);
        }
        return *max_element(dp.begin(), dp.end());
    }
};


int main() {

    cout << Solution().longestIdealString("acfgbd", 2) << '\n';
    // 4

    cout << Solution().longestIdealString("jxhwaysa", 14) << '\n';
    // 5

    return 0;
}
