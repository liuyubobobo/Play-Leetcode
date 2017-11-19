/// Source : https://leetcode.com/problems/house-robber/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 0)
            return 0;

        // the max profit for robbing nums[i...n)
        vector<int> memo(n, 0);
        memo[n - 1] = nums[n - 1];
        for(int i = n - 2 ; i >= 0 ; i --)
            memo[i] = max(memo[i + 1],
                          nums[i] + (i + 2 < n ? memo[i + 2] : 0));

        return memo[0];
    }
};

int main() {

    int nums[] = {2, 1};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));

    cout << Solution().rob(vec) << endl;

    return 0;
}