/// Source : https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
/// Author : liuyubobobo
/// Time   : 2021-06-23

#include <iostream>

using namespace std;


/// Bitwise
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {

        int res = 0;
        while(n){
            n &= (n - 1);
            res ++;
        }
        return res;
    }
};


int main() {

    return 0;
}
