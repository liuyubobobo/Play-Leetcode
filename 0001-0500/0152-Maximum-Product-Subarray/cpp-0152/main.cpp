/// Source : https://leetcode.com/problems/maximum-product-subarray/
/// Author : liuyubobobo
/// Time   : 2021-02-25

#include <iostream>
#include <vector>

using namespace std;


/// Split and Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int res = nums[0] == 0 ? 0 : INT_MIN;
        bool has_zero = false;
        for(int start = next_non_zero(nums, 0), i = start + 1; i <= nums.size(); i ++)
            if(i == nums.size() || nums[i] == 0){
                if(i < nums.size() && nums[i] == 0) has_zero = true;
                res = max(res, solve(nums, start, i - 1));
                start = next_non_zero(nums, i);
                i = start;
            }

        if(has_zero) res = max(res, 0);
        return res;
    }

private:
    int solve(const vector<int>& nums, int l, int r){

        int res = nums[l], cur = nums[l];
        for(int i = l + 1; i <= r; i ++){
            cur *= nums[i];
            res = max(res, cur);
        }

        res = max(res, nums[r]);
        cur = nums[r];
        for(int i = r - 1; i >= l; i --){
            cur *= nums[i];
            res = max(res, cur);
        }
        return res;
    }

    int next_non_zero(const vector<int>& nums, int start){

        for(int i = start; i < nums.size(); i ++)
            if(nums[i] != 0) return i;
        return nums.size();
    }
};


int main() {

    vector<int> nums1 = {-3, 0, 1, -2};
    cout << Solution().maxProduct(nums1) << endl;
    // 1

    return 0;
}
