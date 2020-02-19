/// Source : https://leetcode.com/problems/angle-between-hands-of-a-clock/
/// Author : liuyubobobo
/// Time   : 2020-02-19

#include <iostream>

using namespace std;


/// Mathematics
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    double angleClock(int hour, int minutes) {

        hour %= 12;
        double a = (hour + minutes / 60.0) * 30;
        double b = minutes * 6.0;
        double res = a - b;
        if(res < 0) res += 360.0;
        return res <= 180.0 ? res : 360.0 - res;
    }
};


int main() {

    return 0;
}
