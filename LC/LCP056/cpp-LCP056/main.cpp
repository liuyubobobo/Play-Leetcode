/// Source : https://leetcode-cn.com/problems/6UEx57/
/// Author : liuyubobobo
/// Time   : 2022-04-23

#include <iostream>
#include <vector>
#include <deque>
#include <cassert>
#include <string>

using namespace std;


/// 0-1 BFS
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const string ds = "^v<>";
    int R, C;

public:
    int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {

        R = matrix.size(), C = matrix[0].size();

        vector<vector<pair<int, int>>> g(R * C);
        for(int cx = 0; cx < R; cx ++)
            for(int cy = 0; cy < C; cy ++){
                int od = ds.find(matrix[cx][cy]), cur = cx * C + cy;
                assert(od != string::npos);

                for(int d = 0; d < 4; d ++){
                    int nx = cx + dirs[d][0], ny = cy + dirs[d][1], next = nx * C + ny;
                    if(in_area(nx, ny)) g[cur].push_back({next, (d == od ? 0 : 1)});
                }
            }
        return bfs(R * C, g, start[0] * C + start[1], end[0] * C + end[1]);
    }

private:
    int bfs(int n, const vector<vector<pair<int, int>>>& g, int s, int t){

        vector<int> dis(n, INT_MAX / 2);
        vector<bool> visited(n, false);
        deque<int> q;
        q.push_front(s);
        dis[s] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop_front();
            if(visited[u]) continue;
            visited[u] = true;

            for(const pair<int, int>& p: g[u]){
                int v = p.first, w = p.second;
                if(!visited[v] && w + dis[u] < dis[v]){
                    dis[v] = dis[u] + w;
                    if(w) q.push_back(v);
                    else q.push_front(v);
                }
            }
        }
        return dis[t];
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
