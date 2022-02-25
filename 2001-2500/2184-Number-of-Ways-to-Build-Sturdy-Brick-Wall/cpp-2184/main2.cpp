/// Source : https://leetcode.com/problems/number-of-ways-to-build-sturdy-brick-wall/
/// Author : liuyubobobo
/// Time   : 2022-02-25

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Backtrack + DP
/// Using bit compression
/// Time Complexity: O(|brick|^|brick| + k^2 * height) where k is the way to fill one row
/// Space Complexity: O(k)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int buildWall(int height, int width, vector<int>& bricks) {

        vector<int> rows;
        dfs(bricks, width, 0, 0, rows);

        int n = rows.size();
        if(n == 0) return 0;

        vector<long long> dp(n, 1), tdp(n, 0);
        for(int h = 2; h <= height; h ++){
            tdp.assign(n, 0);
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < n; j ++)
                    tdp[i] += dp[j] * !!!(rows[j] & rows[i]);
                tdp[i] %= MOD;
            }
            dp = tdp;
        }

        return accumulate(dp.begin(), dp.end(), 0ll) % MOD;
    }

private:
    void dfs(const vector<int>& bricks, int width, int cur, int state, vector<int>& rows){

        if(cur == width){
            rows.push_back(state ^ (1 << width));
            return;
        }

        for(int brick: bricks)
            if(cur + brick <= width)
                dfs(bricks, width, cur + brick, state | (1 << (cur + brick)), rows);
        return;
    }
};


int main() {

    vector<int> bricks1 = {1, 2};
    cout << Solution().buildWall(2, 3, bricks1) << endl;
    // 2

    vector<int> bricks2 = {5};
    cout << Solution().buildWall(1, 1, bricks2) << endl;
    // 0

    vector<int> bricks3 = {6, 3, 5, 1, 9};
    cout << Solution().buildWall(76, 9, bricks3) << endl;
    // 201495766

    return 0;
}
