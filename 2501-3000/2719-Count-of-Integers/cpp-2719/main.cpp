/// Source : https://leetcode.com/problems/count-of-integers/description/
/// Author : liuyubobobo
/// Time   : 2023-06-04

#include <iostream>
#include <vector>

using namespace std;


/// Digital DP
/// Time Complexity: O(len(num2) * max_sum)
/// Space Complexity: O(len(num2) * max_sum)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        num1 = sub1(num1);
        long long res = solve(num2, min_sum, max_sum) - solve(num1, min_sum, max_sum);
        return (res + MOD) % MOD;
    }

private:
    long long solve(const string& s, int min_sum, int max_sum){

        int len = s.size();
        vector<vector<long long>> dp(len << 1, vector<long long>(max_sum + 1, -1));
        return dfs(len, s, 0, 0, 0, min_sum, max_sum, dp);
    }

    long long dfs(int len, const string& s, int index, int can_over, int cur_sum,
                  const int min_sum, const int max_sum, vector<vector<long long>>& dp){

        if(index == len) return min_sum <= cur_sum && cur_sum <= max_sum;
        if(cur_sum > max_sum) return 0;
        if(dp[index * 2 + can_over][cur_sum] != -1) return dp[index * 2 + can_over][cur_sum];

        long long res = 0;
        for(int i = 0; i <= (can_over ? 9 : s[index] - '0'); i ++){
            res += dfs(len, s, index + 1, can_over || i < s[index] - '0', cur_sum + i, min_sum, max_sum, dp);
            res %= MOD;
        }
        return dp[index * 2 + can_over][cur_sum] = res;
    }

    string sub1(const string& s){
        string res = s;
        for(int i = res.size() - 1; i >= 0; i --){
            if(res[i] == '0'){
                res[i] = '9';
            }else{
                res[i] -= 1;
                break;
            }
        }

        reverse(res.begin(), res.end());
        while(res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res.size() == 0 ? "0" : res;
    }
};


int main() {

    cout << Solution().count("1", "12", 1, 8) << '\n';

    return 0;
}
