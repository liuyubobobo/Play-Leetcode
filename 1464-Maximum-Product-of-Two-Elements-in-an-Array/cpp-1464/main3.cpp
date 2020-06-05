/// Source : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
/// Author : liuyubobobo
/// Time   : 2020-06-05

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan to find the largest and the second largest
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int a = -1, b = -1;
        for(int e: nums)
            if(e >= a) b = a, a = e;
            else if(e > b) b = e;
        return (a - 1) * (b - 1);
    }
};


int main() {

    return 0;
}
