/// Source : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
/// Author : liuyubobobo
/// Time   : 2022-04-02

#include <iostream>

using namespace std;


/// Bitwise
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {

        int res = 0;
        for(int b = 0; b <= 30; b ++)
            res += ((start & (1 << b)) != (goal & (1 << b)));
        return res;
    }
};


int main() {

    cout << Solution().minBitFlips(10, 7) << '\n';

    return 0;
}
