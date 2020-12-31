/// Source : https://leetcode.com/problems/matchsticks-to-square/description/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <numeric>
#include <vector>
#include <cassert>

using namespace std;


/// Memory Search
///
/// Time Complexity: O(n*2^n)
/// Space Complexity: O(2^n)
class Solution {

private:
    int all, side;

public:
    bool makesquare(vector<int>& nums) {

        if(nums.size() == 0)
            return false;

        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 4)
            return false;

        sort(nums.begin(), nums.end(), greater<int>());
        all = (1 << nums.size()) - 1;
        side = total / 4;

        vector<int> sum(all + 1, -1);
        vector<int> dp(all + 1, -1); // -1 - unvisited, 0 - false, 1 - true
        return dfs(nums, 0, dp, sum);
    }

private:
    bool dfs(const vector<int>& nums, int state,
             vector<int>& dp, vector<int>& sum){

        if(state == all)
            return true;

        if(dp[state] != -1)
            return dp[state];

        int left = getSum(nums, state, sum) % side;

        for(int i = 0; i < nums.size() ; i ++)
            if((state & (1 << i)) == 0 && left + nums[i] <= side
               && dfs(nums, state | (1 << i), dp, sum))
                return dp[state] = 1;
        return dp[state] = 0;
    }

    int getSum(const vector<int>& nums, int state, vector<int>& sum){

        if(sum[state] != -1)
            return sum[state];

        if(state == 0)
            return sum[state] = 0;

        for(int i = 0; i < nums.size() ; i ++)
            if(state & (1 << i))
                return sum[state] =  nums[i] + getSum(nums, state - (1 << i), sum);
        assert(false);
        return -1;
    }
};


int main() {

    return 0;
}