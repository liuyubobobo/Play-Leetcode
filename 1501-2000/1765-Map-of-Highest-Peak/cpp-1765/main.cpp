/// Source : https://leetcode.com/problems/map-of-highest-peak/
/// Author : liuyubobobo
/// Time   : 2021-02-20

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int R, C;

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        R = isWater.size(), C = isWater[0].size();

        vector<vector<int>> res(R, vector<int>(C, -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(isWater[i][j]){
                    q.push({i * C + j, 0});
                    res[i][j] = 0;
                }

        while(!q.empty()){
            int cur = q.front().first, v = q.front().second;
            q.pop();

            int curx = cur / C, cury = cur % C;
            for(int d = 0; d < 4; d ++){
                int nextx = curx + dirs[d][0], nexty = cury + dirs[d][1];
                if(in_area(nextx, nexty) && res[nextx][nexty] == -1){
                    res[nextx][nexty] = v + 1;
                    q.push({nextx * C + nexty, v + 1});
                }
            }
        }
        return res;
    }

private:
    bool in_area(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};


int main() {

    vector<vector<int>> isWater = {{0, 1}, {0, 0}};
    vector<vector<int>> res = Solution().highestPeak(isWater);

    return 0;
}
