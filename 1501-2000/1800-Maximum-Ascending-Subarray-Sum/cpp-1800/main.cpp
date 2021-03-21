/// Source : https://leetcode.com/problems/maximum-ascending-subarray-sum/
/// Author : liuyubobobo
/// Time   : 2021-03-20

#include <iostream>
#include <vector>

using namespace std;


/// Presum + Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int n = nums.size();
        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++)
            presum[i + 1] = presum[i] + nums[i];

        int res = *max_element(nums.begin(), nums.end());
        for(int start = 0; start < n; start ++)
            for(int end = start + 1; end < n; end ++)
                if(ok(nums, start, end))
                    res = max(res, presum[end + 1] - presum[start]);
        return res;
    }

private:
    bool ok(const vector<int>& nums, int a, int b){

        for(int i = a + 1; i <= b; i ++)
            if(nums[i] <= nums[i - 1]) return false;
        return true;
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
