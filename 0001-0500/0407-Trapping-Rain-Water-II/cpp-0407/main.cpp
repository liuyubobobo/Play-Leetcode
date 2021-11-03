/// Source : https://leetcode.com/problems/trapping-rain-water-ii/
/// Author : liuyubobobo
/// Time   : 2021-11-03

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using PQ
/// This solution is analysis is amazing:
/// https://leetcode.com/problems/trapping-rain-water-ii/discuss/89461/Java-solution-using-PriorityQueue
///
/// Time Compelexity: O(R * C * log(R * C))
/// Space Complexity: O(R * C)
class Solution {

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int R, C;

public:
    int trapRainWater(vector<vector<int>>& heightMap) {

        R = heightMap.size(), C = heightMap[0].size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // height, pos
        vector<bool> visited(R * C, false);
        for(int i = 0; i < R; i ++){
            pq.push({heightMap[i][0], i * C + 0});
            pq.push({heightMap[i][C - 1], i * C + C - 1});
            visited[i * C + 0] = visited[i * C + C - 1] = true;
        }
        for(int j = 1; j + 1 < C; j ++){
            pq.push({heightMap[0][j], j});
            pq.push({heightMap[R - 1][j], (R - 1) * C + j});
            visited[j] = visited[(R - 1) * C + j] = true;
        }

        int res = 0;
        while(!pq.empty()){
            int h = pq.top().first, pos = pq.top().second;
            pq.pop();

            int x = pos / C, y = pos % C;
            res += max(0, h - heightMap[x][y]);

            for(int d = 0; d < 4; d ++){
                int nx = x + dirs[d][0], ny = y + dirs[d][1];
                if(in_area(nx, ny) && !visited[nx * C + ny]){
                    pq.push({max(h, heightMap[nx][ny]), nx * C + ny});
                    visited[nx * C + ny] = true;
                }
            }
        }
        return res;
    }

private:
    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    vector<vector<int>> height1 = {
            {12,13,1,12},{13,4,13,12},{13,8,10,12},{12,13,12,12},{13,13,13,13}
    };
    cout << Solution().trapRainWater(height1) << endl;
    // 14

    return 0;
}
