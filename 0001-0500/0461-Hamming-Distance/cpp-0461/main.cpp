/// Source : https://leetcode.com/problems/hamming-distance/
/// Author : liuyubobobo
/// Time   : 2021-05-26

#include <iostream>

using namespace std;


/// bitwise
/// Time Complexity: O(log(max(x, y)))
/// Space Complexity: O(1)
class Solution {
public:
    int hammingDistance(int x, int y) {

        int res = 0;
        while(x | y){
            res += (x & 1) ^ (y & 1);
            x >>= 1;
            y >>= 1;
        }
        return res;
    }
};


int main() {

    return 0;
}
