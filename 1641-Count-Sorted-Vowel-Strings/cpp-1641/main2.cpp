/// Source : https://leetcode.com/problems/count-sorted-vowel-strings/
/// Author : liuyubobobo
/// Time   : 2020-11-01

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Dynamic Programming
/// Tiime Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int countVowelStrings(int n) {

        vector<vector<int>> dp(n, vector<int>(5, 1));
        for(int i = 1; i < n; i ++)
            for(int j = 0; j < 5; j ++){
                dp[i][j] = 0;
                for(int k = 0; k <= j; k ++) dp[i][j] += dp[i - 1][k];
            }
        return accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0);
    }
};


int main() {

    cout << Solution().countVowelStrings(1) << endl;
    // 5

    cout << Solution().countVowelStrings(2) << endl;
    // 15

    cout << Solution().countVowelStrings(33) << endl;
    // 66045

    cout << Solution().countVowelStrings(50) << endl;
    // 316251

    return 0;
}
