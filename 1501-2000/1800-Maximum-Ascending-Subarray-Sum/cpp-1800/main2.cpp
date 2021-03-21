/// Source : https://leetcode.com/problems/maximum-ascending-subarray-sum/
/// Author : liuyubobobo
/// Time   : 2021-03-21

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int cur = nums[0], res = nums[0];
        for(int i = 1; i <= nums.size(); i ++)
            if(i == nums.size() || nums[i] <= nums[i - 1]){
                res = max(res, cur);
                if(i < nums.size()) cur = nums[i];
            }
            else cur += nums[i];
        return res;
    }
};


int main() {

    vector<int> nums1 = {10, 20, 30, 5, 10, 50};
    cout << Solution().maxAscendingSum(nums1) << endl;
    // 65

    vector<int> nums2 = {10, 20, 30, 40, 50};
    cout << Solution().maxAscendingSum(nums2) << endl;
    // 150

    vector<int> nums3 = {12,17,15,13,10,11,12};
    cout << Solution().maxAscendingSum(nums3) << endl;
    // 33

    vector<int> nums4 = {100,10,1};
    cout << Solution().maxAscendingSum(nums4) << endl;
    // 100

    return 0;
}
