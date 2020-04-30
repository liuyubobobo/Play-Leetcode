/// Source : https://leetcode-cn.com/problems/xun-bao/
/// Author : liuyubobobo
/// Time   : 2020-04-29

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;


/// TSP : Dynamic Programming
/// Time Complexity: O(M * M * (1 << M))
/// Time Complexity: O(M * (1 << M))
class Solution {

private:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    const int INF = 1e9;

    int m, n;
    vector<int> Os, Ms;
    int start, end;

public:
    int minimalSteps(vector<string>& maze) {

        m = maze.size(), n = maze[0].size();

        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++){
                int index = i * n + j;
                if(maze[i][j] == 'S') start = index;
                else if(maze[i][j] == 'T') end = index;
                else if(maze[i][j] == 'O') Os.push_back(index);
                else if(maze[i][j] == 'M') Ms.push_back(index);
            }

        vector<int> steps;


        /// Corner Cases
        if(Ms.size() == 0){
            steps = bfs(maze, start);
            return steps[end] == INF ? -1 : steps[end];
        }
        if(Os.size() == 0) return -1;


        /// Pre Calculation
        vector<vector<int>> MO(Ms.size(), vector<int>(Os.size()));
        for(int i = 0; i < Ms.size(); i ++){
            steps = bfs(maze, Ms[i]);
            for(int j = 0; j < Os.size(); j ++)
                MO[i][j] = steps[Os[j]];
        }

        vector<vector<int>> MM(Ms.size(), vector<int>(Ms.size(), INF));
        for(int i = 0; i < Ms.size(); i ++)
            for(int j = i + 1; j < Ms.size(); j ++)
                for(int k = 0; k < Os.size(); k ++)
                    MM[i][j] = MM[j][i] = min(MM[i][j], MO[i][k] + MO[j][k]);

        steps = bfs(maze, end);
        vector<int> ME(Ms.size());
        for(int i = 0; i < Ms.size(); i ++) ME[i] = steps[Ms[i]];

        steps = bfs(maze, start);
        vector<int> SO(Os.size());
        for(int i = 0; i < Os.size(); i ++) SO[i] = steps[Os[i]];


        /// TSP - DP
        int res = INF;
        vector<vector<int>> dp(Ms.size(), vector<int>(1 << Ms.size(), INF));
        for(int start = 0; start < Ms.size(); start ++) {
            int sdis = INF;
            for (int i = 0; i < Os.size(); i++)
                sdis = min(sdis, SO[i] + MO[start][i]);
            dp[start][1 << start] = sdis;
        }

        for(int state = 1; state < (1 << Ms.size()); state ++)
            for(int i = 0; i < Ms.size(); i ++)
                if(dp[i][state] != INF)
                    for(int j = 0; j < Ms.size(); j ++)
                        if(j != i && (state & (1 << j)) == 0)
                            dp[j][state | (1 << j)] = min(dp[j][state | (1 << j)], dp[i][state] + MM[i][j]);

        for(int i = 0; i < Ms.size(); i ++)
            if(dp[i][(1 << Ms.size()) - 1] != INF) {
                dp[i][(1 << Ms.size()) - 1] += ME[i];
                res = min(res, dp[i][(1 << Ms.size()) - 1]);
            }
        return res >= INF ? -1 : res;
    }

private:
    vector<int> bfs(const vector<string>& maze, int s){

        vector<int> step(m * n, INF);

        queue<int> q;
        q.push(s);
        step[s] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            int curx = cur / n, cury = cur % n;
            for(int d = 0; d < 4; d ++){
                int nextx = curx + dirs[d][0], nexty = cury + dirs[d][1], next = nextx * n + nexty;
                if(in_area(nextx, nexty) && maze[nextx][nexty] != '#' && step[next] == INF){
                    step[next] = step[cur] + 1;
                    q.push(next);
                }
            }
        }
        return step;
    }

    bool in_area(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


int main() {

    vector<string> maze1 = {"S#O", "M..", "M.T"};
    cout << Solution().minimalSteps(maze1) << endl;
    // 16

    vector<string> maze2 = {"S#O", "M.#", "M.T"};
    cout << Solution().minimalSteps(maze2) << endl;
    // -1

    vector<string> maze3 = {"S#O", "M.T", "M.."};
    cout << Solution().minimalSteps(maze3) << endl;
    // 17

    vector<string> maze4 = {"...O.",".S#M.","..#T.","....."};
    cout << Solution().minimalSteps(maze4) << endl;
    // 5

    return 0;
}
