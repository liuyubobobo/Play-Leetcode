/// Source : https://leetcode.com/problems/contain-virus/
/// Author : liuyubobobo
/// Time   : 2022-07-19

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Simulation
/// Time Complexity: O((R * C) ^ 2)
/// Space Compelxity: O(R * C)
class Solution {

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int R, C;

public:
    int containVirus(vector<vector<int>>& isInfected) {

        R = isInfected.size(), C = isInfected[0].size();

        // 0 - not infected, 1 - virus
        int res = 0;
        while(true){
            vector<vector<int>> visited(R, vector<int>(C, -1));
            int cc_num = 0;
            for(int i = 0; i < R; i ++)
                for(int j = 0; j < C; j ++)
                    if(isInfected[i][j] == 1 && visited[i][j] == -1){
                        dfs(isInfected, i, j, cc_num ++, visited);
                    }

            if(cc_num == 0) break;

            vector<int> walls(cc_num, 0);
            vector<set<int>> threaten(cc_num);
            for(int i = 0; i < R; i ++)
                for(int j = 0; j < C; j ++){
                    int cc = visited[i][j];
                    if(cc == -1) continue;

                    for(int d = 0; d < 4; d ++){
                        int nx = i + dirs[d][0], ny = j + dirs[d][1];
                        if(in_area(nx, ny) && isInfected[nx][ny] == 0)
                            threaten[cc].insert(nx * C + ny), walls[cc] ++;
                    }
                }

            int max_threatens = 0, max_cc = -1;
            for(int cc = 0; cc < cc_num; cc ++)
                if(threaten[cc].size() > max_threatens)
                    max_threatens = threaten[cc].size(), max_cc = cc;

            if(max_threatens == 0) break;

            res += walls[max_cc];
            for(int i = 0; i < R; i ++)
                for(int j = 0; j < C; j ++)
                    if(visited[i][j] == max_cc) isInfected[i][j] = 2;

            vector<vector<int>> next(R, vector<int>(C, 0));
            for(int i = 0; i < R; i ++)
                for(int j = 0; j < C; j ++){
                    if(isInfected[i][j] != 1) continue;
                    for(int d = 0; d < 4; d ++){
                        int nx = i + dirs[d][0], ny = j + dirs[d][1];
                        if(in_area(nx, ny) && !isInfected[nx][ny]) next[nx][ny] = 1;
                    }
                }

            for(int i = 0; i < R; i ++)
                for(int j = 0; j < C; j ++)
                    if(isInfected[i][j] == 0 && next[i][j])
                        isInfected[i][j] = 1;
        }
        return res;
    }

private:
    void dfs(const vector<vector<int>>& isInfected, int x, int y, int cc,
             vector<vector<int>>& visited){
        visited[x][y] = cc;
        for(int d = 0; d < 4; d ++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(in_area(nx, ny) && isInfected[nx][ny] == 1 && visited[nx][ny] == -1)
                dfs(isInfected, nx, ny, cc, visited);
        }
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    vector<vector<int>> isInfected1 = {
            {0,1,0,0,0,0,0,1},
            {0,1,0,0,0,0,0,1},
            {0,0,0,0,0,0,0,1},
            {0,0,0,0,0,0,0,0}
    };
    cout << Solution().containVirus(isInfected1) << '\n';
    // 10

    vector<vector<int>> isInfected2 = {
            {1,1,1,0,0,0,0,0,0},
            {1,0,1,0,1,1,1,1,1},
            {1,1,1,0,0,0,0,0,0}
    };
    cout << Solution().containVirus(isInfected2) << '\n';
    // 13

    vector<vector<int>> isInfected3 = {
            {1}
    };
    cout << Solution().containVirus(isInfected3) << '\n';
    // 0

    vector<vector<int>> isInfected4 = {
            {0,1,0,1,1,1,1,1,1,0},
            {0,0,0,1,0,0,0,0,0,0},
            {0,0,1,1,1,0,0,0,1,0},
            {0,0,0,1,1,0,0,1,1,0},
            {0,1,0,0,1,0,1,1,0,1},
            {0,0,0,1,0,1,0,1,1,1},
            {0,1,0,0,1,0,0,1,1,0},
            {0,1,0,1,0,0,0,1,1,0},
            {0,1,1,0,0,1,1,0,0,1},
            {1,0,1,1,0,1,0,1,0,1}
    };
    cout << Solution().containVirus(isInfected4) << '\n';
    // 38

    return 0;
}
