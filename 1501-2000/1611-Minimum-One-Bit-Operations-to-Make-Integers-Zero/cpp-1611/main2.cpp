/// Source : https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
/// Author : liuyubobobo
/// Time   : 2020-10-04

#include <iostream>

using namespace std;


/// Grey code to Binary code
/// Ref: https://en.wikipedia.org/wiki/Gray_code
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumOneBitOperations(int n) {

        n ^= n >> 16;
        n ^= n >>  8;
        n ^= n >>  4;
        n ^= n >>  2;
        n ^= n >>  1;
        return n;
    }
};


int main() {

    cout << Solution().minimumOneBitOperations(0) << endl; // 0
    cout << Solution().minimumOneBitOperations(3) << endl; // 2
    cout << Solution().minimumOneBitOperations(6) << endl; // 4
    cout << Solution().minimumOneBitOperations(9) << endl; // 14
    cout << Solution().minimumOneBitOperations(333) << endl; // 393
    cout << Solution().minimumOneBitOperations(284848) << endl; // 495839

    return 0;
}
