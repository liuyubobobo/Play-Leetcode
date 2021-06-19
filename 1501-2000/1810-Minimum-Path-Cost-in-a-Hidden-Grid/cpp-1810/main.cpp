/// Source : https://leetcode.com/problems/minimum-path-cost-in-a-hidden-grid/
/// Author : liuyubobobo
/// Time   : 2021-06-18

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


/// Dijkstra
/// Time Complexity: O((m * n)log(m * n))
/// Space Complexity: O(m * n)

// This is the GridMaster's API interface.
// You should not implement it, or speculate about its implementation
class GridMaster {
    public:
    bool canMove(char direction);
    int move(char direction);
    bool isTarget();
};

class Solution {

private:
    unordered_map<char, pair<int, int>> dirs = {
            {'U', {-1, 0}},
            {'R', {0, 1}},
            {'D', {1, 0}},
            {'L', {0, -1}}
    };

public:
    int findShortestPath(GridMaster &master) {

        vector<vector<int>> g(201, vector<int>(201, -1));
        vector<int> target(2, -1);
        g[100][100] = 0;
        fill(master, g, 100, 100, target);
        // cout << "fill completed" << endl;

        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 100 * 201 + 100});
        while(!pq.empty()){
            int w = pq.top().first, pos = pq.top().second;
            pq.pop();

            int y = pos % 201, x = (pos - y) / 201;
            if(visited.count(pos)) continue;
            visited.insert(pos);

            if(x == target[0] && y == target[1]) return w;

            for(const pair<char, pair<int, int>>& p: dirs){
                int dx = p.second.first, dy = p.second.second;
                int nx = x + dx, ny = y + dy, npos = nx * 201 + ny;
                if(g[nx][ny] != -1 && !visited.count(npos)){
                    pq.push({w + g[nx][ny], npos});
                }
            }
        }
        return -1;
    }

    void fill(GridMaster& master, vector<vector<int>>& g, int x, int y,
              vector<int>& target){

        // cout << x << " " << y << endl;
        if(master.isTarget())
            target[0] = x, target[1] = y;

        for(const pair<char, pair<int, int>>& p: dirs){
            char d = p.first;
            int dx = p.second.first, dy = p.second.second;

            int nx = x + dx, ny = y + dy;
            if(master.canMove(d) && g[nx][ny] == -1){
                g[nx][ny] = master.move(d);
                // cout << "go to " << d << " " << nx << " " << ny << endl;
                fill(master, g, nx, ny, target);
                switch(d){
                    case 'U': master.move('D'); break;
                    case 'D': master.move('U'); break;
                    case 'L': master.move('R'); break;
                    case 'R': master.move('L'); break;
                    default : assert(false);
                }
            }
        }
        // cout << "back to " << x << " " << y << endl;
    }
};


int main() {

    return 0;
}
