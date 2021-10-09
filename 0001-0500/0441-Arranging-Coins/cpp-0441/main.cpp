/// Source : https://leetcode.com/problems/arranging-coins/
/// Author : liuyubobobo
/// Time   : 2021-10-09

#include <iostream>


/// Mathematics
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int arrangeCoins(int n) {

        return int(sqrt(2.0 * n + 0.25) - 0.5 + 1e-6);
    }
};


int main() {
    return 0;
}
