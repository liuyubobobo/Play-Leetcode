/// Source : https://leetcode.com/problems/factorial-trailing-zeroes/
/// Author : liuyubobobo
/// Time   : 2022-03-24

#include <iostream>

using namespace std;


/// Math
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(int p = 5; p <= n; p *= 5) res += n / p;
        return res;
    }
};


int main() {

    return 0;
}
