/// Source : https://leetcode.com/problems/ugly-number/
/// Author : liuyubobobo
/// Time   : 2021-04-10

#include <iostream>

using namespace std;


/// Mathematics
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    bool isUgly(int n) {

        if(n == 0) return false;

        while(n % 2 == 0) n /= 2;
        while(n % 3 == 0) n /= 3;
        while(n % 5 == 0) n /= 5;
        return n == 1;
    }
};


int main() {

    return 0;
}
