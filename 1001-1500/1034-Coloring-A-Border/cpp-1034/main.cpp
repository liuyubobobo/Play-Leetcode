/// Source : https://leetcode.com/problems/coloring-a-border/
/// Author : liuyubobobo
/// Time   : 2019-04-27

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// DFS Connected Components
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {

private:
    const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {

        m = grid.size();
        n = grid[0].size();

        int target = grid[r0][c0];
        if(target == color) return grid;

        set<pair<int, int>> cc;
        dfs(grid, r0, c0, target, cc);

        vector<pair<int, int>> border;
        for(const pair<int, int>& p: cc)
            if(isborder(grid, p.first, p.second, target))
                border.push_back(p);

        for(const pair<int, int>& p: border)
            grid[p.first][p.second] = color;
        return grid;
    }

private:
    void dfs(vector<vector<int>>& grid, int x, int y, int target, set<pair<int, int>>& cc){

        cc.insert(make_pair(x, y));
        for(int i = 0; i < 4; i ++){
            int nextx = x + d[i][0], nexty = y + d[i][1];
            if(nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && grid[nextx][nexty] == target &&
               !cc.count(make_pair(nextx, nexty)))
                dfs(grid, nextx, nexty, target, cc);
        }
    }

    bool isborder(vector<vector<int>>& grid, int x, int y, int target){

        for(int i = 0; i < 4; i ++){
            int nextx = x + d[i][0], nexty = y + d[i][1];
            if(nextx < 0 || nextx >= m || nexty < 0 || nexty >= n)
                return true;
            if(grid[nextx][nexty] != target)
                return true;
        }
        return false;
    }
};


void print_2dvec(const vector<vector<int>>& vec){
    for(const vector<int>& row: vec){
        for(int e: row) cout << e << " "; cout << endl;
    }
}

int main() {

    vector<vector<int>> grid1 = {{1,2,1},{1,2,2},{2,2,1}};
    vector<vector<int>> res1 = Solution().colorBorder(grid1, 1, 1, 2);
    print_2dvec(res1);
    // 1 2 1
    // 1 2 2
    // 2 2 1

    vector<vector<int>> grid2 = {{1,2,1,2,1,2},{2,2,2,2,1,2},{1,2,2,2,1,2}};
    vector<vector<int>> res2 = Solution().colorBorder(grid2, 1, 3, 1);
    print_2dvec(res2);
    // 1 1 1 1 1 2
    // 1 2 1 1 1 2
    // 1 1 1 1 1 2

    return 0;
}