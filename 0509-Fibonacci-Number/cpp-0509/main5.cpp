/// Source : https://leetcode.com/problems/fibonacci-number/
/// Author : liuyubobobo
/// Time   : 2019-01-09

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/// Closed Form
/// https://en.wikipedia.org/wiki/Fibonacci_number
///
/// Time Complexity: O(logn)
/// Space Complexity: O(logn)
class Solution {
public:
    int fib(int N) {

        double a = (1. + sqrt(5.)) / 2.0;
        double b = (1. - sqrt(5.)) / 2.0;
        return (int)((pow(a, N) - pow(b, N)) / sqrt(5) + 0.5);
    }
};


int main() {

    return 0;
}