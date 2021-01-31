/// Source : https://leetcode.com/problems/palindrome-partitioning-ii/
/// Author : liuyubobobo
/// Time   : 2021-01-30

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int minCut(string s) {

        int n = s.size();

        vector<vector<bool>> dp(n + 1);
        dp[1] = vector<bool>(n, true);
        for(int i = 0; i + 1 < n; i ++)
            dp[2].push_back(s[i] == s[i + 1]);

        for(int sz = 3; sz <= n; sz ++)
            for(int i = 0; i + sz <= n; i ++)
                dp[sz].push_back((s[i] == s[i + sz - 1]) && dp[sz - 2][i + 1]);

        vector<int> res(n + 1, INT_MAX);
        res[n] = 0;
        for(int i = n - 1; i >= 0; i --){
            for(int sz = 1; i + sz <= n; sz ++)
                if(dp[sz][i]) res[i] = min(res[i], 1 + res[i + sz]);
        }
        return res[0] - 1;
    }
};


int main() {

    cout << Solution().minCut("aab") << endl;
    // 1

    cout << Solution().minCut("a") << endl;
    // 0

    cout << Solution().minCut("ab") << endl;
    // 1

    cout << Solution().minCut("aaabaa") << endl;
    // 1

    return 0;
}
