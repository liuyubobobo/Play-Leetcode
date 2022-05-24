#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <climits>

using namespace std;


class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {

        int n = stickers.size();

        vector<vector<int>> f(n, vector<int>(26, 0));
        for(int i = 0; i < n; i ++)
            for(char c: stickers[i]) f[i][c - 'a'] ++;

        vector<int> tf(26, 0);
        for(char c: target) tf[c - 'a'] ++;

        map<pair<int, vector<int>>, int> dp;
        int res = dfs(n, f, 0, tf, dp);
        return res >= INT_MAX / 2 ? -1 : res;
    }

private:
    int dfs(int n, const vector<vector<int>>& f, int index, vector<int> tf,
            map<pair<int, vector<int>>, int>& dp){

        if(index == n)
            return accumulate(tf.begin(), tf.end(), 0) == 0 ? 0 : INT_MAX / 2;

        pair<int, vector<int>> state = {index, tf};
        auto iter = dp.find(state);
        if(iter != dp.end()) return iter->second;

        int res = dfs(n, f, index + 1, tf, dp);

        int max_need = 0;
        for(int i = 0; i < 26; i ++)
            if(tf[i] && f[index][i])
                max_need = max(max_need, tf[i] / f[index][i] + !!(tf[i] % f[index][i]));

        for(int k = 1; k <= max_need; k ++){
            for(int i = 0; i < 26; i ++)
                tf[i] = max(0, tf[i] - f[index][i]);
            res = min(res, k + dfs(n, f, index + 1, tf, dp));
        }
        return dp[state] = res;
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
