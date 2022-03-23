/// Source : https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
/// Author : liuyubobobo
/// Time   : 2022-03-23

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Digital DP
/// Time Complexity: O(logn)
/// Space Complexity: O(logn)
class Solution {

private:
    vector<long long> pow10;
    vector<vector<int>> dp;

public:
    int findKthNumber(int n, int k) {

        pow10.assign(15, 1);
        for(int i = 1; i < 15; i ++)
            pow10[i] = pow10[i - 1] * 10ll;

        dp = vector<vector<int>>(2, vector<int>(20, -1));

        string s = to_string(n);
        string cur = "";
        assert(solve(s, cur, 0, k - 1));
        return cur == "" ? 1 : atoi(cur.c_str());
    }

private:
    bool solve(const string& s, string& cur, int index, int k){

        if(k == 0) return true;

        int cnt_total = index == 0 ? 0 : 1;
        for(int d = (index == 0 ? 1 : 0); d <= 9; d ++){
            int cnt = get_cnt(s, cur + (char)('0' + d), index + 1);
            if(k < cnt_total + cnt){
                cur += (char)('0' + d);
                solve(s, cur, index + 1, k - cnt_total);
                return true;
            }
            cnt_total += cnt;
        }
        return false;
    }

    int get_cnt(const string& s, const string& cur, int index){

        int res = 0;
        for(int len = index; len < s.size(); len ++)
            res += pow10[len - index];

        if(cur <= s.substr(0, cur.size()))
            res += get_cnt_dfs(s, index, cur < s.substr(0, cur.size()));
        return res;
    }

    int get_cnt_dfs(const string& s, int index, bool can_over){

        if(index == s.size()) return 1;
        if(dp[can_over][index] != -1) return dp[can_over][index];

        int res = 0;
        for(int d = 0; d <= (can_over ? 9 : (s[index] - '0')); d ++){
            res += get_cnt_dfs(s, index + 1, can_over || d < s[index] - '0');
        }
        return dp[can_over][index] = res;
    }
};


int main() {

    cout << Solution().findKthNumber(13, 2) << '\n';
    // 10

    cout << Solution().findKthNumber(1, 1) << '\n';
    // 1

    cout << Solution().findKthNumber(10, 3) << '\n';
    // 2

    cout << Solution().findKthNumber(100, 10) << '\n';
    // 17

    cout << Solution().findKthNumber(681692778, 351251360) << '\n';
    // 416126219

    return 0;
}
