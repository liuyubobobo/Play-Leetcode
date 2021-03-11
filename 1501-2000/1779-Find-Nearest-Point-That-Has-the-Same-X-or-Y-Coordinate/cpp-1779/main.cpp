/// Source : https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/
/// Author : liuyubobobo
/// Time   : 2021-03-11

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {

        int res = -1, dis = INT_MAX;
        for(int i = 0; i < points.size(); i ++){
            if(x == points[i][0] && abs(y - points[i][1]) < dis)
                res = i, dis = abs(y - points[i][1]);
            if(y == points[i][1] && abs(x - points[i][0]) < dis)
                res = i, dis = abs(x - points[i][0]);
        }
        return res;
    }
};


int main() {

    return 0;
}
