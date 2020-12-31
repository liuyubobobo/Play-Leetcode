/// Source : https://leetcode.com/problems/two-city-scheduling/
/// Author : liuyubobobo
/// Time   : 2019-04-20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {

        vector<vector<int>> res;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
               res.push_back({i, j});

        sort(res.begin(), res.end(), [r0, c0](const vector<int>& v1, const vector<int>& v2){

            int dis1 = abs(v1[0] - r0) + abs(v1[1] - c0);
            int dis2 = abs(v2[0] - r0) + abs(v2[1] - c0);
            return dis1 < dis2;
        });
        return res;
    }
};


int main() {

    return 0;
}