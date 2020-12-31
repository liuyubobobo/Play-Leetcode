/// Source : https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/
/// Author : liuyubobobo
/// Time   : 2019-08-03

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {

        int res1 = 0;
        for(int i = 1; i < nums.size(); i += 2){
            int x = nums[i - 1];
            if(i + 1 < nums.size()) x = min(x, nums[i + 1]);
            x --;
            res1 += max(nums[i] - x, 0);
        }

        int res2 = 0;
        for(int i = 0; i < nums.size(); i += 2){
            int x = INT_MAX;
            if(i - 1 >= 0) x = min(x, nums[i - 1]);
            if(i + 1 < nums.size()) x = min(x, nums[i + 1]);
            x --;
            res2 += max(nums[i] - x, 0);
        }

        return min(res1, res2);
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3};
    cout << Solution().movesToMakeZigzag(nums1) << endl;
    // 2

    vector<int> nums2 = {10, 4, 4, 10, 10, 6, 2, 3};
    cout << Solution().movesToMakeZigzag(nums2) << endl;
    // 13

    return 0;
}