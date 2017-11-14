/// https://leetcode.com/problems/minimum-size-subarray-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-13

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// Sum Prefix
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        assert(s > 0);

        vector<int> sums(nums.size() + 1, 0);
        for(int i = 1 ; i <= nums.size() ; i ++)
            sums[i] = sums[i-1] + nums[i-1];

        int res = nums.size() + 1;
        for(int l = 0 ; l < nums.size() ; l ++)
            for(int r = l ; r < nums.size() ; r ++)
                if(sums[r+1] - sums[l] >= s)
                    res = min(res, r - l + 1);

        if(res == nums.size() + 1)
            return 0;

        return res;
    }
};

int main() {

    int nums[] = {2, 3, 1, 2, 4, 3};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int) );
    int s = 7;

    cout << Solution().minSubArrayLen(s, vec) << endl;

    return 0;
}