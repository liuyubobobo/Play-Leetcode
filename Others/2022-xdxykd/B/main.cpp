/// Source : https://leetcode.cn/contest/ubiquant2022/problems/3PHTGp/
/// Author : liuyubobobo
/// Time   : 2022-08-25

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    const int dirs[8][2] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };
    int R, C;

public:
    int lakeCount(vector<string>& field) {

        R = field.size(), C = field[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                if(field[i][j] == '.' || visited[i][j]) continue;

                dfs(field, i, j, visited);
                res ++;
            }
        return res;
    }

private:
    void dfs(const vector<string>& g, int x, int y, vector<vector<bool>>& visited){

        visited[x][y] = true;
        for(int d = 0; d < 8; d ++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(in_area(nx, ny) && !visited[nx][ny] && g[nx][ny] != '.')
                dfs(g, nx, ny, visited);
        }
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
