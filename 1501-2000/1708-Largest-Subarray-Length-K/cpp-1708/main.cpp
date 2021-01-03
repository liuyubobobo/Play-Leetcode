/// Source : https://leetcode.com/problems/largest-subarray-length-k/
/// Author : liuyubobobo
/// Time   : 2021-01-03

#include <iostream>
#include <vector>

using namespace std;


/// Max
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {

        int maxv = nums[0], start = 0;
        for(int i = 1; i + k <= nums.size(); i ++)
            if(nums[i] > maxv) maxv = nums[i], start = i;
        return vector<int>(nums.begin() + start, nums.begin() + start + k);
    }
};


int main() {

    return 0;
}
