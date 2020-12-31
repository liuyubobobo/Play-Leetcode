/// Source : https://leetcode.com/problems/path-with-minimum-effort/
/// Author : liuyubobobo
/// Time   : 2020-10-24

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Dijkstra
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int R, C;

public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        R = heights.size(), C = heights[0].size();
        vector<vector<int>> dp(R, vector<int>(C, -1));
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            int curdis = pq.top().first, cur = pq.top().second;
            pq.pop();

            int curx = cur / C, cury = cur % C;
            if(visited[curx][cury]) continue;

            visited[curx][cury] = true;
            for(int d = 0; d < 4; d ++){
                int nextx = curx + dirs[d][0], nexty = cury + dirs[d][1];
                if(in_area(nextx, nexty) && !visited[nextx][nexty] &&
                   (dp[nextx][nexty] == -1 || max(dp[curx][cury], abs(heights[nextx][nexty] - heights[curx][cury])) < dp[nextx][nexty])){
                    dp[nextx][nexty] = max(dp[curx][cury], abs(heights[nextx][nexty] - heights[curx][cury]));
                    pq.push({dp[nextx][nexty], nextx * C + nexty});
                }
            }
        }
        return dp[R - 1][C - 1] == -1 ? 0 : dp[R - 1][C - 1];
    }

private:
    bool in_area(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};


int main() {

    vector<vector<int>> heights1 = {{1,2,2},{3,8,2},{5,3,5}};
    cout << Solution().minimumEffortPath(heights1) << endl;
    // 2

    vector<vector<int>> heights2 = {{1,2,3},{3,8,4},{5,3,5}};
    cout << Solution().minimumEffortPath(heights2) << endl;
    // 1

    vector<vector<int>> heights3 = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    cout << Solution().minimumEffortPath(heights3) << endl;
    // 0

    vector<vector<int>> heights4 = {{3}};
    cout << Solution().minimumEffortPath(heights4) << endl;
    // 0

    vector<vector<int>> heights5 = {{1, 10, 6, 7, 9, 10, 4, 9}};
    cout << Solution().minimumEffortPath(heights5) << endl;
    // 9

    return 0;
}
