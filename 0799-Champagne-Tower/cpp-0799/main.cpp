/// Source : https://leetcode.com/problems/champagne-tower/description/
/// Author : liuyubobobo
/// Time   : 2018-03-11

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Recurrence
/// Time Complexity: O(max_row^2)
/// Space Complexity: O(max_row^2)
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<vector<double>> tower;
        for(int i = 0; i < 100; i ++)
            tower.push_back(vector<double>(i + 1, 0.0));

        tower[0][0] = poured;
        for(int i = 0 ; i < tower.size() ; i ++)
            for(int j = 0 ; j <= i ; j ++){
                if(tower[i][j] > 1.0){
                    double left = tower[i][j] - 1.0;
                    tower[i][j] = 1.0;
                    if(i + 1 < tower.size()){
                        tower[i + 1][j] += left / 2;
                        tower[i + 1][j + 1] += left / 2;
                    }
                }
            }

        return tower[query_row][query_glass];
    }
};

int main() {

    cout << Solution().champagneTower(1, 1, 1) << endl; // 0.0
    cout << Solution().champagneTower(2, 1, 1) << endl; // 0.5
    cout << Solution().champagneTower(4, 1, 0) << endl; // 1

    return 0;
}