/// Source : https://leetcode.com/problems/stickers-to-spell-word/
/// Author : liuyubobobo
/// Time   : 2022-05-24

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <climits>

using namespace std;


/// Memoization
/// Time Complexity: O(C(26, 15)?)
/// Space Complexity: O(C(26, 15)?)
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {

        int n = stickers.size();

        vector<vector<int>> f(n, vector<int>(26, 0));
        for(int i = 0; i < n; i ++)
            for(char c: stickers[i]) f[i][c - 'a'] ++;

        vector<int> tf(26, 0);
        for(char c: target) tf[c - 'a'] ++;

        map<vector<int>, int> dp;
        int res = dfs(n, f, tf, dp);
        return res >= INT_MAX / 2 ? -1 : res;
    }

private:
    int dfs(int n, const vector<vector<int>>& f, const vector<int>& tf,
            map<vector<int>, int>& dp){

        if(accumulate(tf.begin(), tf.end(), 0) == 0)
            return 0;

        auto iter = dp.find(tf);
        if(iter != dp.end()) return iter->second;

        int first_need = 0;
        for(;first_need < 26 && tf[first_need] == 0; first_need ++);

        int res = INT_MAX / 2;
        for(int index = 0; index < n; index ++)
            if(f[index][first_need]){
                vector<int> next_f = tf;
                for(int i = 0; i < 26; i ++)
                    next_f[i] = max(next_f[i] - f[index][i], 0);
                res = min(res, 1 + dfs(n, f, next_f, dp));
            }
        return dp[tf] = res;
    }
};


int main() {

    vector<string> stickers1 = {"with","example","science"};
    string target1 = "thehat";
    cout << Solution().minStickers(stickers1, target1) << '\n';
    // 3

    vector<string> stickers2 = {"notice","possible"};
    string target2 = "basicbasic";
    cout << Solution().minStickers(stickers2, target2) << '\n';
    // -1

    return 0;
}
