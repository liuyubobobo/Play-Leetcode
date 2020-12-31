/// Source : https://leetcode.com/problems/rotting-oranges/
/// Author : liuyubobobo
/// Time   : 2019-02-16

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

public:
    int orangesRotting(vector<vector<int>>& grid) {

        assert(grid.size() && grid[0].size());
        m = grid.size(), n = grid[0].size();

        vector<int> rotten;
        int fresh = 0;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(grid[i][j] == 1)
                    fresh ++;
                else if(grid[i][j] == 2)
                    rotten.push_back(i * n + j);

        if(!rotten.size())
            return fresh ? -1 : 0;

        unordered_set<int> used;
        for(int e: rotten) used.insert(e);

        int res = 0;
        while(rotten.size()){

//            cout << "rotten : ";
//            for(int e: rotten) cout << e << " ";
//            cout << endl;

            vector<int> newrotten;
            for(int e: rotten){
                int x = e / n, y = e % n;
                for(int i = 0; i < 4; i ++){
                    int nextx = x + d[i][0], nexty = y + d[i][1];
                    if(nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && grid[nextx][nexty] == 1){
                        grid[nextx][nexty] = 2;
                        newrotten.push_back(nextx * n + nexty);
                        used.insert(nextx * n + nexty);
                    }
                }
            }

            if(newrotten.size()) res ++;
            rotten = newrotten;
        }

        if(!allRotten(grid)) return -1;
        return res;
    }

private:
    bool allRotten(const vector<vector<int>>& grid){
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(grid[i][j] == 1)
                    return false;
        return true;
    }
};


int main() {

    vector<vector<int>> grid1 = {
            {2,1,1},
            {1,1,0},
            {0,1,1}
    };
    cout << Solution().orangesRotting(grid1) << endl;
    // 4

    vector<vector<int>> grid2 = {
            {0, 0},
            {0, 0}
    };
    cout << Solution().orangesRotting(grid2) << endl;
    // 0

    vector<vector<int>> grid3 = {
            {1}
    };
    cout << Solution().orangesRotting(grid3) << endl;
    // -1

    return 0;
}