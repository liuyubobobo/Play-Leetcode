/// Source : https://leetcode.com/problems/number-of-enclaves/
/// Author : liuyubobobo
/// Time   : 2019-03-30

#include <iostream>
#include <vector>

using namespace std;


/// Floodfill
/// Time Complexity: O(n * m)
/// Space Complexity: O(n * m)
class Solution {

private:
    int n, m;
    const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int numEnclaves(vector<vector<int>>& A) {

        if(A.size() == 0 || A[0].size() == 0) return 0;

        n = A.size(), m = A[0].size();
        for(int i = 0; i < n; i ++){
            if(A[i][0]) dfs(A, i, 0);
            if(A[i][m - 1]) dfs(A, i, m - 1);
        }

        for(int j = 0; j < m; j ++){
            if(A[0][j]) dfs(A, 0, j);
            if(A[n - 1][j]) dfs(A, n - 1, j);
        }

        int res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                res += A[i][j];
        return res;
    }

private:
    void dfs(vector<vector<int>>& A, int x, int y){

        A[x][y] = 0;
        for(int i = 0; i < 4; i ++){
            int nextx = x + d[i][0], nexty = y + d[i][1];
            if(in_area(nextx, nexty) && A[nextx][nexty])
                dfs(A, nextx, nexty);
        }
    }

    bool in_area(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};


int main() {

    vector<vector<int>> A1 = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout << Solution().numEnclaves(A1) << endl;
    // 3

    vector<vector<int>> A2 = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
    cout << Solution().numEnclaves(A2) << endl;
    // 0

    return 0;
}