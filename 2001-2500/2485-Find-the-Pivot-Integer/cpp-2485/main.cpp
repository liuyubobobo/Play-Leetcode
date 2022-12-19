/// Source : https://leetcode.com/problems/find-the-pivot-integer/description/
/// Author : liuyubobobo
/// Time   : 2022-12-18

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int pivotInteger(int n) {

        // [1...x] and [x ... n]
        for(int x = 1; x <= n; x ++){
            if((1 + x) * x / 2 == (x + n) * (n - x + 1) / 2) return x;
        }
        return -1;
    }
};


int main() {


    return 0;
}
