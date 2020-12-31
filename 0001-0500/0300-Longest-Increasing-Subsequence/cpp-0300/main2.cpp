/// Source : https://leetcode.com/problems/longest-increasing-subsequence/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

#include <iostream>
#include <vector>
using namespace std;

/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

public:
    int lengthOfLIS(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        // memo[i] is the length of the longest increasing sequence end in nums[i]
        vector<int> memo(nums.size(), 1);
        for(int i = 1 ; i < nums.size() ; i ++)
            for(int j = 0 ; j < i ; j ++)
                if(nums[i] > nums[j])
                    memo[i] = max(memo[i], 1 + memo[j]);

        int res = memo[0];
        for(int i = 1 ; i < nums.size() ; i ++)
            res = max(res, memo[i]);

        return res;
    }
};

int main() {

    int nums1[] = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    cout << Solution().lengthOfLIS(vec1) << endl;
    // 4

    // ---

    int nums2[] = {4, 10, 4, 3, 8, 9};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));
    cout << Solution().lengthOfLIS(vec2) << endl;
    // 3

    // ---

    int nums3[] = {2, 2};
    vector<int> vec3(nums3, nums3 + sizeof(nums3)/sizeof(int));
    cout << Solution().lengthOfLIS(vec3) << endl;
    // 1

    // ---

    int nums4[] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    vector<int> vec4(nums4, nums4 + sizeof(nums4)/sizeof(int));
    cout << Solution().lengthOfLIS(vec4) << endl;
    // 6

    return 0;
}int main() {

    int nums1[] = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    cout << Solution().lengthOfLIS(vec1) << endl;
    // 4

    // ---

    int nums2[] = {4, 10, 4, 3, 8, 9};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));
    cout << Solution().lengthOfLIS(vec2) << endl;
    // 3

    // ---

    int nums3[] = {2, 2};
    vector<int> vec3(nums3, nums3 + sizeof(nums3)/sizeof(int));
    cout << Solution().lengthOfLIS(vec3) << endl;
    // 1

    // ---

    int nums4[] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    vector<int> vec4(nums4, nums4 + sizeof(nums4)/sizeof(int));
    cout << Solution().lengthOfLIS(vec4) << endl;
    // 6

    return 0;
}