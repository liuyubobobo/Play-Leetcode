/// Source : https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
/// Author : liuyubobobo
/// Time   : 2021-03-11

#include <iostream>

using namespace std;


/// 3-based number convert
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    bool checkPowersOfThree(int n) {

        int cur = 1;
        while(cur * 3 <= n) cur *= 3;

        while(cur){
            if(n >= cur) n -= cur;
            cur /= 3;
        }
        return n == 0;
    }
};


int main() {

    return 0;
}
