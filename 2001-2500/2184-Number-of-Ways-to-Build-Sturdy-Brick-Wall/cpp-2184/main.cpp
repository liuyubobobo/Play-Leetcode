/// Source : https://leetcode.com/problems/number-of-ways-to-build-sturdy-brick-wall/
/// Author : liuyubobobo
/// Time   : 2022-02-25

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Backtrack + DP
/// Time Complexity: O(|brick|^|brick| + k^2 * height) where k is the way to fill one row
/// Space Complexity: O(k)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int buildWall(int height, int width, vector<int>& bricks) {

        vector<vector<int>> rows;
        vector<int> row;
        dfs(bricks, width, row, rows);

        for(vector<int>& row: rows){
            for(int i = 1; i < row.size(); i ++)
                row[i] += row[i - 1];
            assert(row.back() == width);
            row.pop_back();
        }

        int n = rows.size();
        if(n == 0) return 0;

        vector<vector<bool>> ok(n, vector<bool>(n, false));
        for(int i = 0; i < n; i ++)
            for(int j = i; j < n; j ++)
                ok[i][j] = get_ok(rows[i], rows[j]), ok[j][i] = ok[i][j];

        vector<long long> dp(n, 1);
        for(int h = 2; h <= height; h ++){
            vector<long long> tdp(n, 0);
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < n; j ++)
                    tdp[i] += dp[j] * ok[i][j];
                tdp[i] %= MOD;
            }
            dp = tdp;
        }
        return accumulate(dp.begin(), dp.end(), 0ll) % MOD;
    }

private:
    bool get_ok(const vector<int>& r1, const vector<int>& r2){
        int i = 0, j = 0;
        while(i < r1.size() && j < r2.size()){
            if(r1[i] == r2[j]) return false;
            if(r1[i] < r2[j]) i ++;
            else j ++;
        }
        return true;
    }

    void dfs(const vector<int>& bricks, int left, vector<int>& row, vector<vector<int>>& rows){

        if(left == 0) rows.push_back(row);
        if(left <= 0) return;

        for(int brick: bricks){
            row.push_back(brick);
            dfs(bricks, left - brick, row, rows);
            row.pop_back();
        }
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
