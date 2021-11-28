/// Source : https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/
/// Author : liuyubobobo
/// Time   : 2021-11-27

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(m + n)
/// Space Complexity: O(1)
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {

        int res = 0;

        int x0 = startPos[0], x1 = homePos[0];
        if(x0 < x1) {
            for (int i = x0 + 1; i <= x1; i ++)
                res += rowCosts[i];
        }
        if(x0 > x1){
            for (int i = x0 - 1; i >= x1; i --)
                res += rowCosts[i];
        }

        int y0 = startPos[1], y1 = homePos[1];
        if(y0 < y1){
            for(int i = y0 + 1; i <= y1; i ++)
                res += colCosts[i];
        }
        if(y0 > y1){
            for(int i = y0 - 1; i >= y1; i --)
                res += colCosts[i];
        }

        return res;
    }
};


int main() {

    return 0;
}
