/// Source : https://leetcode.com/problems/kth-smallest-subarray-sum/
/// Author : liuyubobobo
/// Time   : 2021-07-01

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Binary Search + Two Pointers
/// Time Complexity: O(n * log(sum))
/// Space Complexity: O(1)
class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        int l = *min_element(nums.begin(), nums.end()), r = accumulate(nums.begin(), nums.end(), 0);
        while(l < r){
            int mid = l + (r - l) / 2;
            if(subarr_num(nums, mid) < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }

private:
    int subarr_num(const vector<int>& nums, int t){

        int l = 0, r = -1, sum = 0, res = 0;
        while(l < nums.size()){
            if(r + 1 < nums.size() && sum + nums[r + 1] <= t) {
                sum += nums[++r];
                if(l <= r) res += (r - l + 1);
            }
            else{
                sum -= nums[l ++];
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {2, 1, 3};
    cout << Solution().kthSmallestSubarraySum(nums1, 4) << endl;
    // 3

    vector<int> nums2 = {3, 3, 5, 5};
    cout << Solution().kthSmallestSubarraySum(nums2, 7) << endl;
    // 10

    vector<int> nums3 = {2, 1, 5, 4, 4};
    cout << Solution().kthSmallestSubarraySum(nums3, 3) << endl;
    // 3

    vector<int> nums4 = {1, 2, 4, 4, 9};
    cout << Solution().kthSmallestSubarraySum(nums4, 10) << endl;
    // 10

    return 0;
}
