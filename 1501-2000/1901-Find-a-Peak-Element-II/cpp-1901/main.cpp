/// Source : https://leetcode.com/problems/find-a-peak-element-ii/
/// Author : liuyubobobo
/// Time   : 2021-06-15

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(m*n)
/// Space Complexity: O(1)
class Solution {

private:
    const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++){
                int d = 0;
                for(; d < 4; d ++)
                    if(in_area(i + dirs[d][0], j + dirs[d][1]) && mat[i + dirs[d][0]][j + dirs[d][1]] >= mat[i][j])
                        break;
                if(d == 4) return {i, j};
            }
        return {-1, -1};
    }

private:
    bool in_area(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


int main() {

    return 0;
}
