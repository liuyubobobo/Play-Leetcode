/// Source : https://leetcode.com/problems/01-matrix/description/
/// Author : liuyubobobo
/// Time   : 2018-09-30

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;


/// BFS
/// No need to store pair in the queue:)
///
/// Time Complexity: O(m*n)
/// Space Complexity: O(m*n)
class Solution {

private:
    const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

        if(matrix.size() == 0 || matrix[0].size() == 0)
            return matrix;

        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(matrix[i][j] == 0)
                    res[i][j] = 0;

        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(matrix[i][j] == 0)
                    bfs(matrix, i, j, res);

        return res;
    }

    void bfs(const vector<vector<int>>& matrix, int sx, int sy,
            vector<vector<int>>& res){

        queue<int> q;
        q.push(sx * n + sy);

        while(!q.empty()){
            int x = q.front() / n;
            int y = q.front() % n;
            q.pop();

            for(int k = 0; k < 4; k ++){
                int newX = x + d[k][0], newY = y + d[k][1];
                if(inArea(newX, newY) && res[x][y] + 1 < res[newX][newY]){
                    res[newX][newY] = res[x][y] + 1;
                    q.push(newX * n + newY);
                }
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