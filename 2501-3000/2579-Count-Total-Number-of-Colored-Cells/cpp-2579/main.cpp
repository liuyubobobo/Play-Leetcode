/// Source : https://leetcode.com/problems/count-total-number-of-colored-cells/description/
/// Author : liuyubobobo
/// Time   : 2023-03-04

#include <iostream>

using namespace std;


/// Math
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    long long coloredCells(long long n) {

        return n * n * 2 - (n * 2 - 1);
    }
};


int main() {

    cout << Solution().coloredCells(1) << '\n';
    // 1

    cout << Solution().coloredCells(2) << '\n';
    // 5

    return 0;
}
