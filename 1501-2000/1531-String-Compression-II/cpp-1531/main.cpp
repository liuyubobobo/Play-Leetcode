/// Source : https://leetcode.com/problems/string-compression-ii/
/// Author : liuyubobobo
/// Time   : 2022-10-16

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Memoization
/// Time Complexity: O(27 * 11 * |s| * k)
/// Space Complexity: O(27 * 11 * |s| * k)
class Solution {

public:
    int getLengthOfOptimalCompression(string s, int k) {

        if(all_one_char(s)){
            s = s.substr(0, (int)s.size() - k);
            return len(s.size());
        }

        // dp[pre_char][pre_cnt][index][k]
        vector<vector<vector<vector<int>>>> dp(27, vector<vector<vector<int>>>(11, vector<vector<int>>(s.size(), vector<int>(k + 1, -1))));
        return dfs(s, 26, 0, 0, k, dp);
    }

private:
    int dfs(const string& s, int pre_char, int pre_cnt, int index, int k,
            vector<vector<vector<vector<int>>>>& dp){

        int pre_len = len(pre_cnt);

        if(index == s.size()){
            return pre_len;
        }

        if(dp[pre_char][pre_cnt][index][k] != -1)
            return dp[pre_char][pre_cnt][index][k];

        int res = INT_MAX;
        if(s[index] - 'a' != pre_char)
            res = min(res, pre_len + dfs(s, s[index] - 'a', 1, index + 1, k, dp));
        else
            res = min(res, dfs(s, pre_char, min(pre_cnt + 1, 10), index + 1, k, dp));

        if(k)
            res = min(res, dfs(s, pre_char, pre_cnt, index + 1, k - 1, dp));
        return dp[pre_char][pre_cnt][index][k] = res;
    }

    int len(int cnt){
        if(cnt == 0) return 0;
        else if(cnt == 1) return 1;
        else return 1 + to_string(cnt).size();
    }

    bool all_one_char(const string& s){
        for(int i = 1; i < s.size(); i ++)
            if(s[i] != s[0]) return false;
        return true;
    }
};


int main() {

    cout << Solution().getLengthOfOptimalCompression("aaabcccd", 2) << '\n';
    // 4

    cout << Solution().getLengthOfOptimalCompression("aabbaa", 2) << '\n';
    // 2

    cout << Solution().getLengthOfOptimalCompression("aaaaaaaaaaa", 0) << '\n';
    // 3

    return 0;
}
