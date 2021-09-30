/// Source : https://leetcode.com/problems/rectangle-area/
/// Author : liuyubobobo
/// Time   : 2021-09-29

#include <iostream>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        int total = abs(ax1 - ax2) * abs(ay1 - ay2) + abs(bx1 - bx2) * abs(by1 - by2);

        if(ax2 <= bx1 || bx2 <= ax1) return total;

        if(ay2 <= by1 || by2 <= ay1) return total;

        int x, y;
        if(ax1 <= bx1) x = bx2 <= ax2 ? bx2 - bx1 : ax2 - bx1;
        else x = ax2 <= bx2 ? ax2 - ax1 : bx2 - ax1;

        if(ay1 <= by1) y = by2 <= ay2 ? by2 - by1 : ay2 - by1;
        else y = ay2 <= by2 ? ay2 - ay1 : by2 - ay1;

        return total - x * y;
    }
};


int main() {

    cout << Solution().computeArea(-5, 4, 0, 5, -3, -3, 3, 3) << endl;
    // 41

    return 0;
}
