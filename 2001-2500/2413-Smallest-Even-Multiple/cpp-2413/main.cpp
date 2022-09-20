/// Source : https://leetcode.com/problems/smallest-even-multiple/submissions/
/// Author : liuyubobobo
/// Time   : 2022-09-20

#include <iostream>

using namespace std;


/// Math
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int smallestEvenMultiple(int n) {

        if(n % 2 == 0) return n;
        return n << 1;
    }
};


int main() {

    return 0;
}
