/// Source : https://leetcode.com/problems/numbers-with-1-repeated-digit/
/// Author : liuyubobobo
/// Time   : 2020-04-08

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Digital DP
/// Time Complexity: O(log(N) * 2^10 * 4)
/// Space Complexity: O(logN)
class Solution {

public:
    int numDupDigitsAtMostN(int N) {

        if(N <= 10) return 0;

        vector<int> digits = get_digits(N);
        vector<vector<vector<int>>> dp(digits.size(), vector<vector<int>>(1 << 10, vector<int>(4, -1)));
        return dfs(0, 0, 0b11, digits, dp);
    }

private:
    int dfs(int index, int digits, int state,
            const vector<int>& N, vector<vector<vector<int>>>& dp){

        if(index == N.size()) return 0;
        if(dp[index][digits][state] != -1) return dp[index][digits][state];

        int limit = state & 1, leadzero = state >> 1;

        int bound = limit ? N[index] : 9;
        int res = 0;
        for(int i = 0; i <= bound; i ++){
            int next_limit = limit ? (i == bound ? 1 : 0) : 0;
            if(digits & (1 << i)){
                res += next_limit ? get_num(N, index + 1) + 1 : pow(10, N.size() - index - 1);
            }
            else{
                int next_digits = leadzero && (i == 0) ? digits : (digits | (1 << i));
                int next_leadzero = leadzero ? (i == 0 ? 1 : 0) : 0;
                int next_state = next_leadzero * 2 + next_limit;
                res += dfs(index + 1, next_digits, next_state, N, dp);
            }
        }
        return dp[index][digits][state] = res;
    }

    int get_num(const vector<int>& num, int start){

        int res = 0;
        for(int i = start; i < num.size(); i ++)
            res = res * 10 + num[i];
        return res;
    }

    vector<int> get_digits(int x){

        vector<int> res;
        while(x) res.push_back(x % 10), x /= 10;
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {

    cout << Solution().numDupDigitsAtMostN(20) << endl; // 1
    cout << Solution().numDupDigitsAtMostN(100) << endl; // 10
    cout << Solution().numDupDigitsAtMostN(1000) << endl; // 262
    cout << Solution().numDupDigitsAtMostN(11) << endl; // 1
    cout << Solution().numDupDigitsAtMostN(101) << endl; // 11
    cout << Solution().numDupDigitsAtMostN(110) << endl; // 12
    cout << Solution().numDupDigitsAtMostN(111) << endl; // 13

    return 0;
}