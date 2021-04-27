/// Source : https://leetcode.com/problems/implement-stack-using-queues/
/// Author : liuyubobobo
/// Time   : 2021-04-27

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {

        if(n <= 0) return false;
        while(n % 3 == 0) n /= 3;
        return n == 1;
    }
};


int main() {

    return 0;
}
