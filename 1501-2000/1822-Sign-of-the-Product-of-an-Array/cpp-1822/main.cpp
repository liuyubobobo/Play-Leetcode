/// Source : https://leetcode.com/problems/sign-of-the-product-of-an-array/
/// Author : liuyubobobo
/// Time   : 2021-04-10

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int arraySign(vector<int>& nums) {

        int pos = 0, neg = 0, zero = 0;
        for(int num: nums)
            if(num > 0) pos ++;
            else if(num < 0) neg ++;
            else zero ++;

        if(zero) return 0;
        return neg % 2 ? -1 : 1;
    }
};


int main() {

    return 0;
}
