/// Source : https://leetcode.cn/problems/bianry-number-to-string-lcci/
/// Author : liuyubobobo
/// Time   : 2023-03-01

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    string printBin(double num) {

        string res = "0.";
        double x = 0.5;
        for (int k = 0; k < 7 && num != 0; k ++) {
            if (num >= x) {
                res += '1';
                num -= x;
            } else {
                res += '0';
            }
            x /= 2;
        }
        return num == 0.0 ? res : "ERROR";
    }
};


int main() {

    return 0;
}
