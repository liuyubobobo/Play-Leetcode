/// Source : https://leetcode.com/problems/shortest-bridge/
/// Author : liuyubobobo
/// Time   : 2018-11-03

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;


/// From all the nodes of one component,
/// get the shortest one to the other component,
/// Using BFS
/// We can put all the nodes in one component into the queue :-)
///
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {

private:
    int m, n;
    const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int shortestBridge(vector<vector<int>>& A) {

        m = A.size();
        n = A[0].size();
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(A[i][j]){
                    floodfill(A, i, j);
                    return bfs(A);
                }

        assert(false);
        return -1;
    }

private:
    int bfs(const vector<vector<int>>& A){

        queue<int> q;
        vector<bool> visited(m * n, false);
        vector<int> prev(m * n, -1);

        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(A[i][j] == 2){
                    q.push(i * n + j);
                    visited[i * n + j] = true;
                }

        int cur;
        while(!q.empty()){

            cur = q.front();
            int curx = cur / n, cury = cur % n;
            q.pop();

            if(A[curx][cury] == 1)
                break;

            for(int i = 0; i < 4; i ++){
                int nextx = curx + d[i][0], nexty = cury + d[i][1];
                int next = nextx * n + nexty;
                if(inArea(nextx, nexty) && !visited[next]){
                    visited[next] = true;
                    prev[next] = cur;
                    q.push(next);
                }
            }
        }

        int res = 0;
        while(cur != -1){
            if(!A[cur / n][cur % n])
                res ++;
            cur = prev[cur];
        }
        return res;
    }

    void floodfill(vector<vector<int>>& A, int x, int y){

        A[x][y] = 2;
        for(int i = 0; i < 4; i ++){
            int nextx = x + d[i][0], nexty = y + d[i][1];
            if(inArea(nextx, nexty)){
                if(A[nextx][nexty] == 1)
                    floodfill(A, nextx, nexty);
            }
        }
    }

    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


int main() {

    return 0;
}