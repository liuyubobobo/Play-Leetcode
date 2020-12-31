/// Source : https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
/// Author : liuyubobobo
/// Time   : 2017-11-03

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        int res = 1;
        for(int start = 0, i = 1; i <= nums.size() ;){
            if(i == nums.size() || nums[i] <= nums[i-1] ){
                res = max(res, i - start);
                start = i;
                i = start + 1;
            }
            else
                i ++;
        }

        return res;
    }
};

int main() {

    int nums1[5] = {1, 3, 5, 4, 7};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    cout << Solution().findLengthOfLCIS(vec1) << endl;
    // 3

    // ---

    int nums2[] = {2, 2, 2, 2, 2};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));
    cout << Solution().findLengthOfLCIS(vec2) << endl;
    // 1

    return 0;
}