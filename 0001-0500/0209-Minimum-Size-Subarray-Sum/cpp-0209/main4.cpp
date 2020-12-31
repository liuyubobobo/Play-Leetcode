/// https://leetcode.com/problems/minimum-size-subarray-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-13

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


// Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        assert(s > 0);

        int l = 0 , r = -1; // sliding window: nums[l...r]
        int sum = 0;
        int res = nums.size() + 1;

        while(l < nums.size()){

            if(r + 1 < nums.size() && sum < s)
                sum += nums[++r];
            else
                sum -= nums[l++];

            if(sum >= s)
                res = min(res, r - l + 1);
        }

        return res == nums.size() + 1 ? 0 : res;
    }
};


int main() {

    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int s1 = 7;
    cout << Solution().minSubArrayLen(s1, nums1) << endl;

    return 0;
}