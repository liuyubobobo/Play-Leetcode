/// Source : https://leetcode.com/problems/unique-paths-iii/
/// Author : liuyubobobo
/// Time   : 2020-04-28

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// State Compression + Dynamic Programming
/// Time Complexity: O(m * n * 2 ^ (m * n))
/// Space Complexity: O(m * n * 2 ^ (m * n))
class Solution {

private:
    int m, n;
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int uniquePathsIII(vector<vector<int>>& grid) {

        m = grid.size(), n = grid[0].size();
        int start, end, k = 0;
        map<int, int> posToIndex, indexToPos;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++){
                int pos = i * n + j;
                if(grid[i][j] == 1)
                    start = pos, grid[i][j] = 0;
                else if(grid[i][j] == 2)
                    end = pos, grid[i][j] = 0;

                if(grid[i][j] == -1) continue;

                posToIndex[pos] = k;
                indexToPos[k] = pos;
                k ++;
            }
        vector<vector<int>> dp(k, vector<int>(1 << k, 0));
        dp[posToIndex[start]][1 << posToIndex[start]] = 1;
        for(int state = 1; state < (1 << k); state ++)
            for(int i = 0; i < k; i ++)
                if((state & (1 << i)) && dp[i][state]){
                    int pos = indexToPos[i], x = pos / n, y = pos %n;
                    for(int d = 0; d < 4; d ++) {
                        int nextx = x + dirs[d][0], nexty = y + dirs[d][1], next = nextx * n + nexty;
                        if(in_area(nextx, nexty) && grid[nextx][nexty] != -1 && (state & (1 << next)) == 0)
                            dp[posToIndex[next]][state | (1 << posToIndex[next])] += dp[i][state];
                    }
                }
        return dp[posToIndex[end]][(1 << k) - 1];
    }

private:
    bool in_area(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


int main() {

    vector<vector<int>> g0 = {
            {1,0},
            {0,0},
            {0,2}
    };
    cout << Solution().uniquePathsIII(g0) << endl;
    // 1

    vector<vector<int>> g1 = {
            {1,0,0,0},
            {0,0,0,0},
            {0,0,2,-1}
    };
    cout << Solution().uniquePathsIII(g1) << endl;
    // 2

    vector<vector<int>> g2 = {
            {1,0,0,0},
            {0,0,0,0},
            {0,0,0,2}
    };
    cout << Solution().uniquePathsIII(g2) << endl;
    // 4

    vector<vector<int>> g3 = {
            {0,0,0,0,0},
            {0,2,1,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
    };
    cout << Solution().uniquePathsIII(g3) << endl;
    // 8

    return 0;
}