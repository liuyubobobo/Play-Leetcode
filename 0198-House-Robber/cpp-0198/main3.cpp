/// Source : https://leetcode.com/problems/house-robber/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19
#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming, with O(1) space
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 0)
            return 0;

        int preMax = 0, curMax = 0;
        for(int i = n - 1 ; i >= 0 ; i --) {
            int temp = curMax;
            curMax = max(curMax, nums[i] + preMax);
            preMax = temp;
        }
        return curMax;
    }
};

int main() {

    int nums[] = {2, 1};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));

    cout << Solution().rob(vec) << endl;

    return 0;
}