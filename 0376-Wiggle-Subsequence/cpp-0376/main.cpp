/// Source : https://leetcode.com/problems/wiggle-subsequence/submissions/
/// Author : liuyubobobo
/// Time   : 2020-12-12

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        if(nums.size() <= 1) return nums.size();

        nums = del_dup(nums);

        if(nums.size() <= 2) return nums.size();

        int diff = nums[1] - nums[0], res = 2;
        for(int i = 2; i < nums.size(); i ++)
            if((nums[i] - nums[i - 1]) * diff < 0)
                res ++, diff = nums[i] - nums[i - 1];
        return res;
    }

private:
    vector<int> del_dup(const vector<int>& nums){

        vector<int> res = {nums[0]};
        for(int i = 1; i < nums.size(); i ++)
            if(nums[i] != res.back()) res.push_back(nums[i]);
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 7, 4, 9, 2, 5};
    cout << Solution().wiggleMaxLength(nums1) << endl;
    // 6

    vector<int> nums2 = {1,17,5,10,13,15,10,5,16,8};
    cout << Solution().wiggleMaxLength(nums2) << endl;
    // 7

    vector<int> nums3 = {1,2,3,4,5,6,7,8,9};
    cout << Solution().wiggleMaxLength(nums3) << endl;
    // 2

    return 0;
}
