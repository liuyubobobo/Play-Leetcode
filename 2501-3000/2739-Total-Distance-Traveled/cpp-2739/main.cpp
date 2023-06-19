/// Source : https://leetcode.com/problems/total-distance-traveled/description/
/// Author : liuyubobobo
/// Time   : 2023-06-18

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(mainTank)
/// Space Complexity: O(1)
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {

        int res = 0;
        while(mainTank >= 5 && additionalTank) {
            res += 50;

            mainTank = mainTank - 5 + 1;
            additionalTank --;
        }
        return res + mainTank * 10;
    }
};


int main() {

    return 0;
}
