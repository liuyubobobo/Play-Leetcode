/// Source : https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
/// Author : liuyubobobo
/// Time   : 2020-05-09

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(k * R * C * (R + C))
/// Space Complexity: O(k * R * C)
class Solution {

private:
    const int MOD = 1e9 + 7;
    int R, C;

public:
    int ways(vector<string>& pizza, int k) {

        R = pizza.size(), C = pizza[0].size();
        vector<vector<int>> cnt(R + 1, vector<int>(C + 1, 0));
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                cnt[i + 1][j + 1] = cnt[i][j + 1] + cnt[i + 1][j] - cnt[i][j] + (pizza[i][j] == 'A');

        vector<vector<int>> dp(k, vector<int>(R * C, -1));
        return dfs(k - 1, 0, cnt, dp);
    }

private:
    int dfs(int k, int pos, const vector<vector<int>> &cnt, vector<vector<int>>& dp){

        if(dp[k][pos] != -1) return dp[k][pos];

        int x = pos / C, y = pos % C;
        if(!k) return dp[k][pos] = ok(cnt, x, y, R - 1, C - 1);

        int res = 0;
        for(int i = x + 1; i < R; i ++)
            if(ok(cnt, x, y, i - 1, C - 1))
                res += dfs(k - 1, i * C + y, cnt, dp), res %= MOD;

        for(int j = y + 1; j < C; j ++)
            if(ok(cnt, x, y, R - 1, j - 1))
                res += dfs(k - 1, x * C + j, cnt, dp), res %= MOD;

        return dp[k][pos] = res;
    }

    bool ok(const vector<vector<int>>& cnt, int x1, int y1, int x2, int y2){
        return cnt[x2 + 1][y2 + 1] - cnt[x2 + 1][y1] - cnt[x1][y2 + 1] + cnt[x1][y1];
    }
};


int main() {

    vector<string> pizza1 = {"A..","AAA","..."};
    cout << Solution().ways(pizza1, 3) << endl;
    // 3

    vector<string> pizza2 = {"A..","AA.","..."};
    cout << Solution().ways(pizza2, 3) << endl;
    // 1

    vector<string> pizza3 = {"A..","A..","..."};
    cout << Solution().ways(pizza3, 1) << endl;
    // 1

    return 0;
}
