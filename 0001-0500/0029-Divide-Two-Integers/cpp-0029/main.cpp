/// Source : https://leetcode.com/problems/divide-two-integers/
/// Author : liuyubobobo
/// Time   : 2021-02-27

#include <iostream>

using namespace std;


/// Division
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {

        long long res = (long long)dividend / divisor;
        return (res > INT_MAX || res < INT_MIN) ? INT_MAX : res;
    }
};


int main() {

    return 0;
}
