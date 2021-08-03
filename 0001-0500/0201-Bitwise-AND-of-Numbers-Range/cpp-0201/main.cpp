/// Source : https://leetcode.com/problems/bitwise-and-of-numbers-range/
/// Author : liuyubobobo
/// Time   : 2021-08-03

#include <iostream>

using namespace std;


/// Bit-wise
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        int cur = 0;
        for(int i = 30; i >= 0; i --){
            if(left < cur + (1 << i) && cur + (1 << i) <= right)
                break;
            else if(left >= cur + (1 << i))
                cur += (1 << i);
        }
        return cur;
    }
};


int main() {

    cout << Solution().rangeBitwiseAnd(5, 7) << endl;
    // 4

    return 0;
}
