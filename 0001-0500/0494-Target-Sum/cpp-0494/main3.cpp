/// Source : https://leetcode.com/problems/target-sum/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Memory Search
/// Using TreeSet
///
/// Time Complexity: O(n * maxNum * log(n * maxNum))
/// Space Complexity: O(n * maxNum)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        map<pair<int, int>, int> dp;
        return dfs(nums, 0, S, dp);
    }

private:
    int dfs(const vector<int>& nums, int index, int S,
            map<pair<int, int>, int>& dp){

        if(index == nums.size())
            return S == 0;

        pair<int, int> p = make_pair(index, S);
        if(dp.count(p))
            return dp[p];

        int ret = 0;
        ret += dfs(nums, index + 1, S - nums[index], dp);
        ret += dfs(nums, index + 1, S + nums[index], dp);
        return dp[p] = ret;
    }
};


int main() {

    vector<int> nums = {1, 1, 1, 1, 1};
    cout << Solution().findTargetSumWays(nums, 3) << endl;

    return 0;
}