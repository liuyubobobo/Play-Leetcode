/// Source : https://leetcode.cn/problems/pond-sizes-lcci/
/// Author : liuyubobobo
/// Time   : 2023-06-22

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// DFS
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    int R, C;
    const int dirs[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1},
                            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

public:
    vector<int> pondSizes(vector<vector<int>>& land) {

        R = land.size(); C = land[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        vector<int> res;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                if(visited[i][j] || land[i][j]) continue;
                res.push_back(dfs(land, i, j, visited));
            }
        sort(res.begin(), res.end());
        return res;
    }

private:
    int dfs(const vector<vector<int>>& land, int cx, int cy, vector<vector<bool>>& visited){

        visited[cx][cy] = true;
        int res = 1;
        for(int d = 0; d < 8; d ++){
            int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
            if(in_area(nx, ny) && !visited[nx][ny] && !land[nx][ny])
                res += dfs(land, nx, ny, visited);
        }
        return res;
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
