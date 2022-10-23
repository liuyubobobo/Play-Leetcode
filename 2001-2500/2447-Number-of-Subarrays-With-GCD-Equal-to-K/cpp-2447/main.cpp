/// Source : https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/
/// Author : liuyubobobo
/// Time   : 2022-10-22

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2 * log(max_nums))
/// Space Complexity: O(log(max_nums))
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {

        int n = nums.size();
        int res = 0;
        for(int l = 0; l < n; l ++){
            if(nums[l] == k) res ++;
            int cur_g = nums[l];
            for(int r = l + 1; r < n; r ++){
                cur_g = gcd(cur_g, nums[r]);
                if(cur_g == k) res ++;
            }
        }
        return res;
    }

private:
    int gcd(int a, int b){
        if(a > b) swap(a, b);
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};


int main() {

    vector<int> nums1 = {9, 3, 1, 2, 6, 3};
    cout << Solution().subarrayGCD(nums1, 3) << '\n';
    // 4

    vector<int> nums2 = {4};
    cout << Solution().subarrayGCD(nums2, 7) << '\n';
    // 0

    vector<int> nums3 = {3, 3, 4, 1, 2};
    cout << Solution().subarrayGCD(nums3, 1) << '\n';
    // 10

    return 0;
}
