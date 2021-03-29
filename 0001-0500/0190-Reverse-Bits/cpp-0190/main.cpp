/// Source : https://leetcode.com/problems/reverse-bits/
/// Author : liuyubobobo
/// Time   : 2021-03-28

#include <iostream>


/// Bitwise Operations
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t res = 0;
        for(int i = 0; i < 32; i ++){
            res = (res << 1) + (n & 1);
            n >>= 1;
        }
        return res;
    }
};


int main() {

    return 0;
}
