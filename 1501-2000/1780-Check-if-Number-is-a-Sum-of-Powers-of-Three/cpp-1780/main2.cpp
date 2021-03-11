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

        while(n){
            if(n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};


int main() {

    return 0;
}
