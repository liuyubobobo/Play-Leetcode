/// Source : https://leetcode.com/problems/alphabet-board-path/
/// Author : liuyubobobo
/// Time   : 2019-07-30

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming Space Optimized
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int tribonacci(int n) {

        if(n == 0) return 0;
        if(n == 1 | n == 2) return 1;

        int a = 0, b = 1, c = 1;
        for(int i = 3; i <= n; i ++){
            int d = a + b + c;
            a = b, b = c, c = d;
        }
        return c;
    }
};


int main() {

    return 0;
}