/// Source : https://leetcode.com/problems/count-the-number-of-ideal-arrays/
/// Author : liuyubobobo
/// Time   : 2022-07-10

#include <iostream>
#include <vector>

using namespace std;


/// Backtrack + Math
/// Using dp is faster than multiplication reverse in this problem
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int idealArrays(int n, int maxValue) {

        vector<vector<long long>> dp(n + 1, vector<long long>(20, 0ll));
        dp[1][0] = dp[1][1] = 1;
        for(int i = 2; i <= n; i ++){
            dp[i][0] = 1;
            if(i < 20) dp[i][i] = 1;
            for(int k = 1; k < min(i, 20); k ++)
                dp[i][k] = (dp[i - 1][k - 1] + dp[i - 1][k]) % MOD;
        }

        vector<int> seq;
        return go(seq, n, maxValue, dp);
    }

private:
    long long go(vector<int>& seq, int n, int maxValue,
                 const vector<vector<long long>>& dp){

        long long res = 0;
        if(seq.empty()){
            for(int i = 1; i <= maxValue; i ++){
                seq.push_back(i);
                res += go(seq, n, maxValue, dp);
                seq.pop_back();
            }
            return res % MOD;
        }

        res += dp[n - 1][seq.size() - 1];

        if(seq.size() == n) return res;

        for(int d = 2; seq.back() * d <= maxValue; d ++){
            seq.push_back(seq.back() * d);
            res += go(seq, n, maxValue, dp);
            seq.pop_back();
        }
        return res % MOD;
    }
};


int main() {

    cout << Solution().idealArrays(2, 5) << '\n';
    // 10

    cout << Solution().idealArrays(5, 3) << '\n';
    // 11

    cout << Solution().idealArrays(5878, 2900) << '\n';
    // 465040898

    cout << Solution().idealArrays(1e4, 1e4) << '\n';
    // 22940607

    return 0;
}
