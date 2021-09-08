/// Source : https://leetcode.com/problems/best-meeting-point/
/// Author : liuyubobobo
/// Time   : 2021-09-08

#include <iostream>
#include <vector>

using namespace std;


/// deal with x and y separately in Manhattan Distance Problem
/// Time Complexity: O(mnlog(mn))
/// Space Complexity: O(mn)
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {

        vector<int> rows, cols;
        for(int i = 0; i < grid.size(); i ++)
            for(int j = 0; j < grid[i].size(); j ++)
                if(grid[i][j] == 1){
                    rows.push_back(i);
                    cols.push_back(j);
                }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        int m = rows.size();

        int x = rows[m / 2], y = cols[m / 2];

        int d = 0;
        for(int i = 0; i < m; i ++)
            d += abs(x - rows[i]) + abs(y - cols[i]);
        return d;
    }
};


int main() {

    return 0;
}
