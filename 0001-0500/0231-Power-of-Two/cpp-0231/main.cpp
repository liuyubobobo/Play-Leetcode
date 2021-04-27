/// Source : https://leetcode.com/problems/power-of-two/
/// Author : liuyubobobo
/// Time   : 2021-04-21

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n <= 0) return false;
        while(n % 2 == 0) n /= 2;
        return n == 1;
    }
};


int main() {

    return 0;
}
