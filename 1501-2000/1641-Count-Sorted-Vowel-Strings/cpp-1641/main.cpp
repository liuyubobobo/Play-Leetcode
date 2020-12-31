/// Source : https://leetcode.com/problems/count-sorted-vowel-strings/
/// Author : liuyubobobo
/// Time   : 2020-10-31

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Tiime Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int countVowelStrings(int n) {

        vector<vector<int>> dp(n + 1, vector<int>(5, -1));
        return dfs(n, 0, 0, dp);
    }

private:
    int dfs(int n, int index, int letter, vector<vector<int>>& dp){

        if(index == n) return 1;
        if(dp[index][letter] != -1) return dp[index][letter];

        int res = 0;
        for(int i = letter; i < 5; i ++)
            res += dfs(n, index + 1, i, dp);
        return dp[index][letter] = res;
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
