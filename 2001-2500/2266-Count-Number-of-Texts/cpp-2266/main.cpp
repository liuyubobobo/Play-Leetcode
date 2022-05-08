/// Source : https://leetcode.com/problems/count-number-of-texts/
/// Author : liuyubobobo
/// Time   : 2022-05-07

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    const vector<int> valid = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
    const long long MOD = 1e9 + 7;

public:
    int countTexts(string pressedKeys) {

        int n = pressedKeys.size();
        vector<long long> dp(n, -1);
        return dfs(n, pressedKeys, 0, dp);
    }

private:
    long long dfs(int n, const string& s, int index, vector<long long>& dp){

        if(index == n) return 1;
        if(dp[index] != -1) return dp[index];

        long long res = 0;
        for(int i = index; i < n && s[i] == s[index] && i - index + 1 <= valid[s[index] - '0']; i ++)
            res += dfs(n, s, i + 1, dp), res %= MOD;
        return dp[index] = res;
    }
};


int main() {

    cout << Solution().countTexts("22233") << '\n';
    // 8

    cout << Solution().countTexts("222222222222222222222222222222222222") << '\n';
    // 82876089

    return 0;
}
