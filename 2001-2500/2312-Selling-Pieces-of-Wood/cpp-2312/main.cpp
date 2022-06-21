/// Source : https://leetcode.com/problems/selling-pieces-of-wood/
/// Author : liuyubobobo
/// Time   : 2022-06-18

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// DP - Knapback
/// Time Complexity: O(m * n * n + n * m * m + m * n * (m + n))
/// Space Complexity: O(m * n)
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {

        // 0 - any, 1 - h is fixed, 2 - w is fixed
        vector<vector<vector<long long>>> dp(3, vector<vector<long long>>(m + 1, vector<long long>(n + 1, -1)));

        map<int, map<int, long long>> H, W;
        for(const vector<int>& price: prices){
            int h = price[0], w = price[1], v = price[2];
            H[h][w] = max(H[h][w], (long long)v);
            W[w][h] = max(W[w][h], (long long)v);
        }

        vector<int> h_choices;
        vector<vector<long long>> Hdp(m + 1, vector<long long>(n + 1, 0));
        for(const pair<int, map<int, long long>>& p: H){
            int h = p.first;
            h_choices.push_back(h);
            const map<int, long long>& items = p.second;

            for(int W = 1; W <= n; W ++){
                for(const pair<int, long long>& item: items){
                    int weight = item.first;
                    long long value = item.second;

                    if(W >= weight)
                        Hdp[h][W] = max(Hdp[h][W], Hdp[h][W - weight] + value);
                }
            }
        }

        vector<int> w_choices;
        vector<vector<long long>> Wdp(n + 1, vector<long long>(m + 1, 0));
        for(const pair<int, map<int, long long>>& p: W){
            int w = p.first;
            w_choices.push_back(w);
            const map<int, long long>& items = p.second;

            for(int W = 1; W <= m; W ++) {
                for (const pair<int, long long> &item: items) {
                    int weight = item.first;
                    long long value = item.second;

                    if(W >= weight)
                        Wdp[w][W] = max(Wdp[w][W], Wdp[w][W - weight] + value);
                }
            }
        }

        return dfs(0, m, n, h_choices, w_choices, Hdp, Wdp, dp);
    }

private:
    long long dfs(int state, int m, int n, const vector<int>& h_choices, const vector<int>& w_choices,
                  const vector<vector<long long>>& Hdp, const vector<vector<long long>>& Wdp,
                  vector<vector<vector<long long>>>& dp){

        if(m <= 0 || n <= 0) return 0;
        if(dp[state][m][n] != -1) return dp[state][m][n];

        if(state == 1) return dp[state][m][n] = Hdp[m][n];
        if(state == 2) return dp[state][m][n] = Wdp[n][m];

        long long res = 0;
        for(int h_option: h_choices){
            if(h_option > m) break;
            res = max(res, dfs(1, h_option, n, h_choices, w_choices, Hdp, Wdp, dp) + dfs(0, m - h_option, n, h_choices, w_choices, Hdp, Wdp, dp));
        }
        for(int w_option: w_choices){
            if(w_option > n) break;
            res = max(res, dfs(2, m, w_option, h_choices, w_choices, Hdp, Wdp, dp) + dfs(0, m, n - w_option, h_choices, w_choices, Hdp, Wdp, dp));
        }
        return dp[state][m][n] = res;
    }
};


int main() {

    vector<vector<int>> prices1 = {{1, 4, 2}, {2, 2, 7}, {2, 1, 3}};
    cout << Solution().sellingWood(3, 5, prices1) << '\n';
    // 19

    vector<vector<int>> prices2 = {{3, 2, 10}, {1, 4, 2}, {4, 1, 3}};
    cout << Solution().sellingWood(4, 6, prices2) << '\n';
    // 32

    vector<vector<int>> prices3 = {{4, 1, 18}, {4, 2, 5}, {1, 1, 20}, {3, 1, 21}};
    cout << Solution().sellingWood(4, 2, prices3) << '\n';
    // 160

    return 0;
}
