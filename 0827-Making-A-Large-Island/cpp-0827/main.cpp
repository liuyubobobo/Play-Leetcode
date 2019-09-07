/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-15

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// DFS + HashMap
/// Time Complexity: O(n * m)
/// Space Complexity: O(n * m)
class Solution {

private:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int n, m;

public:
    int largestIsland(vector<vector<int>>& grid) {

        n = grid.size(), m = grid[0].size();
        vector<int> sz = {0, 0};
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(grid[i][j] == 1)
                    sz.push_back(dfs(grid, i, j, sz.size()));

//        cout << "sz : "; for(int e: sz) cout << e << " "; cout << endl;
//        cout << "grrid : " << endl;
//        for(int i = 0; i < grid.size(); i ++){
//            for(int e: grid[i]) cout << e << " "; cout << endl;
//        }

        int res = 0;
        for(int x = 0; x < n; x ++)
            for(int y = 0; y < m; y ++)
                if(grid[x][y] == 0){
                    int tres = 1;
                    unordered_set<int> set;
                    for(int d = 0; d < 4; d ++){
                        int nextx = x + dirs[d][0], nexty = y + dirs[d][1];
                        if(in_area(nextx, nexty) && !set.count(grid[nextx][nexty]))
                            tres += sz[grid[nextx][nexty]],
                            set.insert(grid[nextx][nexty]);
                    }
                    res = max(res, tres);
                }
        return res == 0 ? *max_element(sz.begin(), sz.end()) : res;
    }

private:
    int dfs(vector<vector<int>>& grid, int x, int y, int ccid){

        grid[x][y] = ccid;
        int res = 1;
        for(int d = 0; d < 4; d ++){
            int nextx = x + dirs[d][0], nexty = y + dirs[d][1];
            if(in_area(nextx, nexty) && grid[nextx][nexty] == 1)
                res += dfs(grid, nextx, nexty, ccid);
        }
        return res;
    }

    bool in_area(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};


int main() {

    vector<vector<int>> grid1 = {{1, 0}, {0, 1}};
    cout << Solution().largestIsland(grid1) << endl;
    // 3

    vector<vector<int>> grid2 = {{1, 1}, {1, 0}};
    cout << Solution().largestIsland(grid2) << endl;
    // 4

    return 0;
}