/// Source : https://leetcode.com/problems/the-maze/description/
/// Author : liuyubobobo
/// Time   : 2018-07-11

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

/// BFS
/// Time Complexity: O(mn)
/// Space Complexity: O(mn)
class Solution {

private:
    const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;

public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {

        n = maze.size();
        if(n == 0) return false;
        m = maze[0].size();
        if(m == 0) return false;

        assert(start.size() == 2 && destination.size() == 2);
        assert(inArea(start[0], start[1]) && maze[start[0]][start[1]] == 0);
        assert(inArea(destination[0], destination[1]) &&
                maze[destination[0]][destination[1]] == 0);

        queue<pair<int, int>> q;
        q.push(make_pair(start[0], start[1]));

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[start[0]][start[1]] = true;

        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();

            for(int i = 0; i < 4 ; i ++){
                pair<int, int> next = go(maze, cur, i);
                if(!visited[next.first][next.second]){
                    if(next.first == destination[0] && next.second == destination[1])
                        return true;

                    q.push(next);
                    visited[next.first][next.second] = true;
                }
            }
        }

        return false;
    }

private:
    pair<int, int> go(const vector<vector<int>>& maze,
                      pair<int, int> pos, int i){
        assert(maze[pos.first][pos.second] == 0);
        while(true){
            int nextX = pos.first + d[i][0];
            int nextY = pos.second + d[i][1];
            if(inArea(nextX, nextY) && maze[nextX][nextY] == 0){
                pos.first = nextX;
                pos.second = nextY;
            }
            else
                return pos;
        }
        assert(false);
        return make_pair(-1, -1);
    }

    bool inArea(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    vector<vector<int>> maze1 = {
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0},
            {1, 1, 0, 1, 1},
            {0, 0, 0, 0, 0}
    };
    vector<int> start1 = {0, 4};
    vector<int> destination1 = {4, 4};
    print_bool(Solution().hasPath(maze1, start1, destination1));
    // True

    vector<vector<int>> maze2 = {
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0},
            {1, 1, 0, 1, 1},
            {0, 0, 0, 0, 0}
    };
    vector<int> start2 = {0, 4};
    vector<int> destination2 = {3, 2};
    print_bool(Solution().hasPath(maze2, start2, destination2));
    // False

    return 0;
}