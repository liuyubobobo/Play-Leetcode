/// Source : https://leetcode.com/problems/circle-and-rectangle-overlapping/
/// Author : liuyubobobo
/// Time   : 2020-04-08

#include <iostream>

using namespace std;


/// Recenter the circle and use Mathematics
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    bool checkOverlap(int r, int x_center, int y_center, int x1, int y1, int x2, int y2) {

        x1 -= x_center, y1 -= y_center;
        x2 -= x_center, y2 -= y_center;

        int minx = 0;
        if(x1 >= 0 && x2 >= 0) minx = x1;
        else if(x1 <= 0 && x2 <= 0) minx = x2;

        int miny = 0;
        if(y1 >= 0 && y2 >= 0) miny = y1;
        else if(y1 <= 0 && y2 <= 0) miny = y2;

        return minx * minx + miny * miny <= r * r;
    }
};


int main() {

    cout << Solution().checkOverlap(2, 2, 1, 4, 1, 5, 5) << endl;
    // true

    return 0;
}
