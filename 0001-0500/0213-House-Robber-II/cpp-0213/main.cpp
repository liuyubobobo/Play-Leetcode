/// Source : https://leetcode.com/problems/house-robber-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-11-15

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// Two Pass House Robber I Problem
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 0)
            return 0;

        if(n == 1)
            return nums[0];

        if(n == 2)
            return max(nums[0], nums[1]);

        return max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1));
    }

private:
    int rob(const vector<int>& nums, int start, int end){

        int preMax = nums[start];
        int curMax = max(preMax, nums[start+1]);
        for(int i = start + 2 ; i <= end ; i ++){
            int temp = curMax;
            curMax = max(nums[i] + preMax, curMax);
            preMax = temp;
        }

        return curMax;
    }
};

int main() {

    vector<int> nums = {2, 7, 9, 3, 1};
    cout << Solution().rob(nums) << endl;

    return 0;
}