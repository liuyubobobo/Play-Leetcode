/// Source : https://leetcode.com/problems/count-lattice-points-inside-a-circle/
/// Author : liuyubobobo
/// Time   : 2022-04-23

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(x_range * y_range * |circles|)
/// Space Compelxity: O(1)
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {

        int minx = INT_MAX, maxx = INT_MIN, miny = INT_MAX, maxy = INT_MIN;
        for(const vector<int>& circle: circles){
            int x = circle[0], y = circle[1], r = circle[2];
            minx = min(minx, x - r), maxx = max(maxx, x + r);
            miny = min(miny, y - r), maxy = max(maxy, y + r);
        }

        int res = 0;
        for(int x = minx; x <= maxx; x ++)
            for(int y = miny; y <= maxy; y ++){
                bool ok = false;
                for(const vector<int>& circle: circles){
                    int x0 = circle[0], y0 = circle[1], r0 = circle[2];
                    if((x - x0) * (x - x0) + (y - y0) * (y - y0) <= r0 * r0){
                        ok = true;
                        break;
                    }
                }
                res += ok;
            }
        return res;
    }
};


int main() {

    return 0;
}
