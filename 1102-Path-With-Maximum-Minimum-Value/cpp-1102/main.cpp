/// Source : https://leetcode.com/problems/path-with-maximum-minimum-value/
/// Author : liuyubobobo
/// Time   : 2019-06-30

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Binary Search
/// Time Complexity: O(log(max(A)) * m * n)
/// Space Complexity: O(1)
class Solution {

private:
    int m, n;

public:
    int maximumMinimumPath(vector<vector<int>>& A) {

        m = A.size(), n = A[0].size();

        int min_value = A[0][0], max_value = A[0][0];
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                min_value = min(min_value, A[i][j]),
                max_value = max(max_value, A[i][j]);

        int l = min_value, r = max_value;
        while(l < r){
            int mid = l + (r - l + 1) / 2;
            if(ok(A, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

private:
    bool ok(const vector<vector<int>>& A, int K){

        if(A[0][0] < K || A[m - 1][n - 1] < K) return false;

        const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<int> q;
        q.push(0);

        vector<bool> visited(m * n, false);
        visited[0] = true;

        while(!q.empty()){
            int cx = q.front() / n, cy = q.front() % n;
            q.pop();

            for(int i = 0; i < 4; i ++){
                int nx = cx + d[i][0], ny = cy + d[i][1];
                int index = nx * n + ny;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && A[nx][ny] >= K && !visited[index]){
                    visited[index] = true;
                    q.push(index);
                }
            }
        }
        return visited.back();
    }
};


int main() {

    return 0;
}