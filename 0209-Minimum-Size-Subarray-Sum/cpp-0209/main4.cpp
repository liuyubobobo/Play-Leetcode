/// https://leetcode.com/problems/minimum-size-subarray-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-13

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// Sliding Window
// Another Implementation
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        assert(s > 0);

        int l = 0 , r = -1; // sliding window: nums[l...r]
        int sum = 0;
        int res = nums.size() + 1;

        while(r + 1 < nums.size()){

            while(r + 1 < nums.size() && sum < s)
                sum += nums[++r];

            if(sum >= s)
                res = min(res, r - l + 1);

            while(l < nums.size() && sum >= s){
                sum -= nums[l++];
                if(sum >= s)
                    res = min(res, r - l + 1);
            }
        }

        if(res == nums.size() + 1)
            return 0;
        return res;
    }
};

int main() {

    int nums[] = {2, 3, 1, 2, 4, 3};
    vector<int> vec( nums, nums + sizeof(nums)/sizeof(int) );
    int s = 7;

    cout << Solution().minSubArrayLen(s, vec) << endl;

    return 0;
}