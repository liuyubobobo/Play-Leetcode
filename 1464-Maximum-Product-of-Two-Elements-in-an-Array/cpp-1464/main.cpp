/// Source : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
/// Author : liuyubobobo
/// Time   : 2020-05-30

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int res = 0;
        for(int i = 0; i < nums.size(); i ++)
            for(int j = i + 1; j < nums.size(); j ++)
                res = max(res, (nums[i] - 1) * (nums[j] - 1));
        return res;
    }
};


int main() {

    return 0;
}
