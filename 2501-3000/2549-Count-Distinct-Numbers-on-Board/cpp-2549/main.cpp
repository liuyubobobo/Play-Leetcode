/// Source : https://leetcode.com/problems/count-distinct-numbers-on-board/description/
/// Author : liuyubobobo
/// Time   : 2023-01-28

#include <iostream>
#include <vector>

using namespace std;


/// Math
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int distinctIntegers(int n) {
        return n == 1 ? 1 : n - 1;
    }
};


int main() {

    return 0;
}
