/// Source : https://leetcode.com/problems/house-robber/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// Another way to define the states
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if( n == 0 )
            return 0;

        // the max profit for robbing nums[0...i]
        vector<int> memo(n, 0);
        memo[0] = nums[0];
        for(int i = 1 ; i < n ; i ++)
            memo[i] = max(memo[i - 1],
                          nums[i] + (i - 2 >= 0 ? memo[i - 2] : 0));

        return memo[n-1];
    }
};

int main() {

    int nums[] = {2, 1};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));

    cout << Solution().rob(vec) << endl;

    return 0;
}