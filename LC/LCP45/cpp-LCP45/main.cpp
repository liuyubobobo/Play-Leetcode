/// Source : https://leetcode-cn.com/problems/kplEvH/
/// Author : liuyubobobo
/// Time   : 2021-09-25

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <set>

using namespace std;


/// BFS
/// Time Complexity: O(R * C * max_terrain)
/// Space Complexity: O(R * C * max_terrain)
class Solution {

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int R, C;

public:
    vector<vector<int>> bicycleYard(vector<int>& position, vector<vector<int>>& terrain, vector<vector<int>>& obstacle) {

        R = terrain.size(), C = terrain[0].size();

        set<pair<int, int>> visited;
        queue<pair<int, int>> q; // pos, speed
        q.push({position[0] * C + position[1], 1});
        visited.insert({position[0] * C + position[1], 1});
        set<pair<int, int>> res;
        while(!q.empty()){
            int cx = q.front().first / C, cy = q.front().first % C, speed = q.front().second;
            q.pop();

            for(int d = 0; d < 4; d ++){
                int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
                if(!in_area(nx, ny)) continue;

                int npos = nx * C + ny, new_speed = speed + terrain[cx][cy] - terrain[nx][ny] - obstacle[nx][ny];
                if(new_speed <= 0) continue;
                if(visited.count({npos, new_speed})) continue;

                visited.insert({npos, new_speed});
                if(new_speed == 1) res.insert({nx, ny});
                q.push({npos, new_speed});
            }
        }

        vector<vector<int>> resv;
        for(const pair<int,int>& p: res)
            resv.push_back({p.first, p.second});
        return resv;
    }

private:
    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


void print_vec(const vector<vector<int>>& v){

    for(const vector<int>& row: v){
        cout << '(';
        for(int e: row) cout << e << ' ';
        cout << ')';
    }
    cout << endl;
}

int main() {

    vector<int> pos1 = {0, 0};
    vector<vector<int>> terrain1 = {{0, 0}, {0, 0}}, o1 = {{0, 0}, {0, 0}};
    print_vec(Solution().bicycleYard(pos1, terrain1, o1));
    // [[0,1],[1,0],[1,1]]

    vector<int> pos2 = {1, 1};
    vector<vector<int>> terrain2 = {{5, 0}, {0, 6}}, o2 = {{0, 6}, {7, 0}};
    print_vec(Solution().bicycleYard(pos2, terrain2, o2));
    // 0 1

    return 0;
}
