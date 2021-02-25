/// Source : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
/// Author : liuyubobobo
/// Time   : 2021-02-25

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and Two Pointers
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        vector<int> a = nums;
        sort(a.begin(), a.end());

        int l = 0;
        while(l < nums.size() && nums[l] == a[l]) l ++;

        int r = nums.size() - 1;
        while(r >= 0 && nums[r] == a[r]) r --;

        if(r < l) return 0;
        return r - l + 1;
    }
};


int main() {

    vector<int> nums1 = {2, 6, 4, 8, 10, 9, 15};
    cout << Solution().findUnsortedSubarray(nums1) << endl;
    // 5

    return 0;
}
