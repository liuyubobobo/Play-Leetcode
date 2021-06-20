/// Source : https://leetcode.com/problems/count-sub-islands/
/// Author : liuyubobobo
/// Time   : 2021-06-19

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// DFS and set compare
/// Time Complexity: O((R * C)^2)
/// Space Complexity: O(R * C)
class Solution {

private:
    int R, C;
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        R = grid1.size(), C = grid1[0].size();

        vector<vector<int>> cc1(R, vector<int>(C, -1));
        vector<unordered_set<int>> islands1;
        get_island(grid1, cc1, islands1);

        vector<vector<int>> cc2(R, vector<int>(C, -1));
        vector<unordered_set<int>> islands2;
        get_island(grid2, cc2, islands2);

        int res = 0;
        unordered_set<int> visited;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                if(grid2[i][j] == 0 || grid1[i][j] == 0) continue;

                int cc_index = cc2[i][j];
                if(visited.count(cc_index)) continue;

                if(contains(islands1[cc1[i][j]], islands2[cc_index])){
                    res ++;
//                    cout << "check " << i << " " << j << endl;
                }
                visited.insert(cc_index);
            }
        return res;
    }

private:
    bool contains(const unordered_set<int>& S, const unordered_set<int>& s){

        for(int e: s)
            if(!S.count(e)) return false;
        return true;
    }

    void get_island(const vector<vector<int>>& g,
                    vector<vector<int>>& cc, vector<unordered_set<int>>& islands){

        int cc_index = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(cc[i][j] == -1 && g[i][j] == 1){
                    dfs(g, i, j, cc, cc_index ++);
                    islands.push_back(unordered_set<int>());
                }

        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(cc[i][j] != -1)
                    islands[cc[i][j]].insert(i * C + j);
    }

    void dfs(const vector<vector<int>>& g, int x, int y,
             vector<vector<int>>& cc, int cc_index){

        cc[x][y] = cc_index;

        for(int d = 0; d < 4; d ++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(in_area(nx, ny) && g[nx][ny] == 1 && cc[nx][ny] == -1)
                dfs(g, nx, ny, cc, cc_index);
        }
    }

    bool in_area(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};

int main() {

    vector<vector<int>> g11 = {
            {1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}
    };
    vector<vector<int>> g12 = {
            {1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}
    };
    cout << Solution().countSubIslands(g11, g12) << endl;
    // 3

    return 0;
}
