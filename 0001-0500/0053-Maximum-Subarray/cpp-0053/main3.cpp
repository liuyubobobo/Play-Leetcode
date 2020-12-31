/// Source : https://leetcode.com/problems/maximum-subarray/
/// Author : liuyubobobo
/// Time   : 2020-04-03

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Divide and Conqure
/// Time Complexity: O(nlogn)
/// Space Complexity: O(logn)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        assert(nums.size());
        return maxSubArray(nums, 0, nums.size() - 1);
    }

private:
    int maxSubArray(const vector<int>& nums, int l, int r){

        if(l == r) return nums[l];

        int mid = (l + r) / 2;
        int res = max(maxSubArray(nums, l, mid),
                      maxSubArray(nums, mid + 1, r));
        return max(res, crossSum(nums, l, mid, r));
    }

    int crossSum(const vector<int>& nums, int l, int mid, int r){

        int lres = nums[mid];
        int sum = lres;
        for(int i = mid - 1; i >= l; i --){
            sum += nums[i];
            lres = max(lres, sum);
        }

        int rres = nums[mid + 1];
        sum = rres;
        for(int i = mid + 2; i <= r; i ++){
            sum += nums[i];
            rres = max(rres, sum);
        }

        return lres + rres;
    }
};


int main() {

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray(nums) << endl;
    // 6

    return 0;
}
