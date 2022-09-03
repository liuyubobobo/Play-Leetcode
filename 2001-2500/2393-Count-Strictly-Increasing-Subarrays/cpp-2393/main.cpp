/// Source : https://leetcode.com/problems/count-strictly-increasing-subarrays/
/// Author : liuyubobobo
/// Time   : 2022-09-03

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Compelxity: O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums) {

        int n = nums.size();
        long long res = 0;
        int l = 0, r = -1;
        while(l < n){
            if(r + 1 < n && (r + 1 == l || nums[r] < nums[r + 1]))
                r ++;
            else{
                res += r - l + 1;
                l ++;
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1,3,5,4,4,6};
    cout << Solution().countSubarrays(nums1) << '\n';
    // 10

    vector<int> nums2 = {1,2, 3,4,5};
    cout << Solution().countSubarrays(nums2) << '\n';
    // 15

    return 0;
}
