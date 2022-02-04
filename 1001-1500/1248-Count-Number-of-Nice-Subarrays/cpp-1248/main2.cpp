/// Source : https://leetcode.com/problems/count-number-of-nice-subarrays/
/// Author : liuyubobobo
/// Time   : 2022-02-04

#include <iostream>
#include <vector>

using namespace std;


/// Presum + Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        return f(n, nums, k) - f(n, nums, k - 1);
    }

private:
    long long f(int n, const vector<int>& nums, int k){

        int l = 0, r = -1, cur_odd = 0;
        long long res = 0;
        while(l < n){
            if(r + 1 < n && cur_odd + nums[r + 1] % 2 <= k){
                r ++;
                res += (r - l + 1);
                cur_odd += nums[r] % 2;
            }
            else{
                cur_odd -= nums[l] % 2;
                l ++;
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 1, 2, 1, 1};
    cout << Solution().numberOfSubarrays(nums1, 3) << endl;
    // 2

    return 0;
}
