/// Source : https://leetcode.com/problems/valid-perfect-square/
/// Author : liuyubobobo
/// Time   : 2021-11-03

#include <iostream>

using namespace std;


/// Math
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {

        int x = (int)(sqrt(num) + 1e-6);
        return x * x == num;
    }
};


int main() {

    return 0;
}
