/// Source : https://leetcode.com/problems/maximum-erasure-value/
/// Author : liuyubobobo
/// Time   : 2020-12-19

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        unordered_set<int> set;
        int l = 0, r = -1, res = 0, cur = 0;
        while(l < nums.size()){
            if(r + 1 < nums.size() && !set.count(nums[r + 1])){
                r ++;
                cur += nums[r];
                set.insert(nums[r]);
            }
            else{
                cur -= nums[l];
                set.erase(nums[l]);
                l ++;
            }
            res = max(res, cur);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {4, 2, 4, 5, 6};
    cout << Solution().maximumUniqueSubarray(nums1) << endl;
    // 17

    vector<int> nums2 = {5,2,1,2,5,2,1,2,5};
    cout << Solution().maximumUniqueSubarray(nums2) << endl;
    // 8

    return 0;
}
