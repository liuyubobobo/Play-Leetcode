/// Source : https://leetcode.com/problems/power-of-four/
/// Author : liuyubobobo
/// Time   : 2021-04-27

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        while(n % 4 == 0) n /= 4;
        return n == 1;
    }
};


int main() {

    return 0;
}
