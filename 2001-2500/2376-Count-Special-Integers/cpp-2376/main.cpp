/// Source : https://leetcode.com/problems/count-special-integers/
/// Author : liuyubobobo
/// Time   : 2022-08-13

#include <iostream>
#include <vector>

using namespace std;


/// Digital DP
/// Time Complexity: O(|s| * 2^|s|) where s is the string of n
/// Space Complexity: O(|s| * 2^|s|)
class Solution {
public:
    int countSpecialNumbers(int n) {

        string s = to_string(n);

        long long res = 0;
        for(int len = 1; len <= s.size(); len ++){
            vector<vector<vector<long long>>> dp(len, vector<vector<long long>>(2, vector<long long>(1024, -1)));
            res += dfs(len == s.size() ? s : string(len, '9'), 0, false, 0, dp);
        }
        return res;
    }

private:
    long long dfs(const string& s, int index, bool can_up, int state,
                  vector<vector<vector<long long>>>& dp){

        if(index == s.size()) return 1ll;
        if(dp[index][can_up][state] != -1) return dp[index][can_up][state];

        long long res = 0;
        if(can_up){
            for(int d = (index == 0 ? 1 : 0); d <= 9; d ++)
                if((state & (1 << d)) == 0)
                    res += dfs(s, index + 1, can_up, state | (1 << d), dp);
        }
        else{
            for(int d = (index == 0 ? 1 : 0); d <= s[index] - '0'; d ++)
                if((state & (1 << d)) == 0)
                    res += dfs(s, index + 1, d < s[index] - '0', state | (1 << d), dp);
        }
        return dp[index][can_up][state] = res;
    }
};


int main() {

    cout << Solution().countSpecialNumbers(20) << '\n';
    // 19

    cout << Solution().countSpecialNumbers(5) << '\n';
    // 5

    cout << Solution().countSpecialNumbers(135) << '\n';
    // 110

    return 0;
}
