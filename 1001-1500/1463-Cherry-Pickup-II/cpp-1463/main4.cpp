/// Source : https://leetcode.com/problems/cherry-pickup-ii/
/// Author : liuyubobobo
/// Time   : 2020-05-30

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Dynamic Programming with State Compression + Rolling Array + Optimization
/// Time Complexity: O(C^2 * R)
/// Space Complexity: O(C^2)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int R = grid.size(), C = grid[0].size();
        unordered_map<int, int> dp;
        dp[0 * C + C - 1] = grid[0][0] + grid[0][C - 1];
        for(int i = 1; i < R; i ++){

            unordered_map<int, int> tdp;
            for(const pair<int, int>& p: dp){
                int a = p.first / C, b = p.first % C;
                for(int j1 = -1; j1 <= 1; j1 ++)
                    if(a + j1 >= 0 && a + j1 < C)
                        for(int j2 = -1; j2 <= 1; j2 ++)
                            if(b + j2 >= 0 && b + j2 < C && a + j1 < b + j2){
                                int next = (a + j1) * C + b + j2;
                                tdp[next] = max(tdp[next], p.second + grid[i][a + j1] + grid[i][b + j2]);
                            }
            }
            dp = tdp;
        }

        int res = 0;
        for(const pair<int, int>& p: dp) res = max(res, p.second);
        return res;
    }
};


int main() {

    vector<vector<int>> g1 = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout << Solution().cherryPickup(g1) << endl;
    // 24

    vector<vector<int>> g2 = {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
    cout << Solution().cherryPickup(g2) << endl;
    // 28

    vector<vector<int>> g3 = {{1,0,0,3},{0,0,0,3},{0,0,3,3},{9,0,3,3}};
    cout << Solution().cherryPickup(g3) << endl;
    // 22

    vector<vector<int>> g4 = {{1,1},{1,1}};
    cout << Solution().cherryPickup(g4) << endl;
    // 4

    return 0;
}
