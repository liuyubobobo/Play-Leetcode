/// https://leetcode.com/problems/minimum-size-subarray-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-13

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

// Sum Prefix + Binary Search
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        assert(s > 0);

        vector<int> sums(nums.size() + 1, 0);
        for(int i = 1 ; i <= nums.size() ; i ++)
            sums[i] = sums[i-1] + nums[i-1];

        int res = nums.size() + 1;
        for(int l = 0 ; l < (int)nums.size() - 1 ; l ++){
            auto r_bound = lower_bound(sums.begin(), sums.end(), sums[l] + s);
            if(r_bound != sums.end()){
                int r = r_bound - sums.begin();
                res = min(res, r - l);
            }
        }

        if(res == nums.size() + 1)
            return 0;

        return res;
    }
};

int main() {

    int nums1[] = {2, 3, 1, 2, 4, 3};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int) );
    int s1 = 7;
    cout << Solution().minSubArrayLen(s1, vec1) << endl;
    // 2

    // ---

    vector<int> vec2;
    int s2 = 100;
    cout << Solution().minSubArrayLen(s2, vec2) << endl;

    return 0;
}