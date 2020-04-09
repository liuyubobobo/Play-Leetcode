/// Source : https://leetcode.com/problems/circle-and-rectangle-overlapping/
/// Author : liuyubobobo
/// Time   : 2020-04-08

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(N)
/// Space Complexity: O(1)
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {

        if(x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2) return true;

        int N = 1000000;
        for(int i = 0; i < N; i ++){
            if(in_circle(x1 + (double)i / N * (x2 - x1), y2, x_center, y_center, radius))
                return true;
            if(in_circle(x2, y2 - (double)i / N * (y2 - y1), x_center, y_center, radius))
                return true;
            if(in_circle(x2 - (double)i / N * (x2 - x1), y1, x_center, y_center, radius))
                return true;
            if(in_circle(x1, y1 + (double)i / N * (y2 - y1), x_center, y_center, radius))
                return true;
        }
        return false;
    }

private:
    bool in_circle(double tx, double ty, double cx, double cy, double r){
        return (cx - tx) * (cx - tx) + (cy - ty) * (cy - ty) <= r * r + 1e-8;
    }
};


int main() {

    cout << Solution().checkOverlap(2, 2, 1, 4, 1, 5, 5) << endl;
    // true

    return 0;
}
