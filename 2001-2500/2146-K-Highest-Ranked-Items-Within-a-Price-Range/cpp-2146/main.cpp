/// Source : https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/
/// Author : liuyubobobo
/// Time   : 2022-01-22

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(R * C + klogk)
/// Space Complexity: O(R * C + k)
class Solution {

private:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int R, C;

public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {

        R = grid.size(), C = grid[0].size();
        vector<vector<int>> dis(R, vector<int>(C, -1));

        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        dis[start[0]][start[1]] = 0;
        vector<pair<pair<int, int>, pair<int, int>>> items; // dis, price, r, c
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();

            if(grid[x][y] > 1 && pricing[0] <= grid[x][y] && grid[x][y] <= pricing[1])
                items.push_back({{dis[x][y], grid[x][y]}, {x, y}});

            for(int d = 0; d < 4; d ++){
                int nx = x + dirs[d][0], ny = y + dirs[d][1];
                if(in_area(nx, ny) && grid[nx][ny] && dis[nx][ny] == -1){
                    q.push({nx, ny});
                    dis[nx][ny] = dis[x][y] + 1;
                }
            }
        }

        sort(items.begin(), items.end());
        vector<vector<int>> res;
        for(int i = 0; i < items.size() && i < k; i ++)
            res.push_back({items[i].second.first, items[i].second.second});
        return res;
    }

private:
    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
