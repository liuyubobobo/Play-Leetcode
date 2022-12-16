/// Source : https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/description/
/// Author : liuyubobobo
/// Time   : 2022-12-02

#include <iostream>

using namespace std;


/// Math
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int numberOfCuts(int n) {

        if(n == 1) return 0;

        int k = 1;
        while(n % 2 == 0) k <<= 1, n >>= 1;
        return n * ((k + 1) / 2);
    }
};


int main() {

    return 0;
}
