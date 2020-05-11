/// Source : https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
/// Author : liuyubobobo
/// Time   : 2020-05-10

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming with Space Optimization
/// Time Complexity: O(k * R * C * (R + C))
/// Space Complexity: O(R * C)
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

        vector<int> dp(R * C, 0);
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                dp[i * C + j] = ok(cnt, i, j, R - 1, C - 1);

        for(int t = 1; t < k; t ++){
            vector<int> tdp(R * C, 0);
            for(int r = 0; r < R; r ++)
                for(int c = 0; c < C; c ++){
                    
                    for(int i = r + 1; i < R; i ++)
                        if(ok(cnt, r, c, i - 1, C - 1))
                            tdp[r * C + c] += dp[i * C + c],
                            tdp[r * C + c] %= MOD;

                    for(int j = c + 1; j < C; j ++)
                        if(ok(cnt, r, c, R - 1, j - 1))
                            tdp[r * C + c] += dp[r * C + j],
                            tdp[r * C + c] %= MOD;
                }
            dp = tdp;
        }
        return dp[0];
    }

private:
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
