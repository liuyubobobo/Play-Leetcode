/// Source : https://leetcode.com/problems/target-sum/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14

#include <iostream>
#include <vector>

using namespace std;


/// Backtracking
/// Time Complexity: O(2^n)
/// Space Complexity: O(n)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        return dfs(nums, 0, 0, S);
    }

private:
    int dfs(const vector<int>& nums, int index, int res, int S){

        if(index == nums.size())
            return res == S;

        int ret = 0;
        ret += dfs(nums, index + 1, res - nums[index], S);
        ret += dfs(nums, index + 1, res + nums[index], S);
        return ret;
    }
};


int main() {

    vector<int> nums = {1, 1, 1, 1, 1};
    cout << Solution().findTargetSumWays(nums, 3) << endl;

    return 0;
}