/// Source : https://leetcode.com/problems/matchsticks-to-square/description/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;


/// Dynamic Programming
///
/// Time Complexity: O(n*2^n)
/// Space Complexity: O(2^n)
class Solution {

public:
    bool makesquare(vector<int>& nums) {

        if(nums.size() == 0)
            return false;

        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 4)
            return false;

        sort(nums.begin(), nums.end(), greater<int>());
        int all = (1 << nums.size()) - 1;
        int side = total / 4;

        vector<int> sum(all + 1, 0);
        for(int i = 1; i <= all; i ++)
            for(int j = 0; j < nums.size() ; j ++)
                if(i & (1 << j)){
                    sum[i] = nums[j] + sum[i - (1 << j)];
                    break;
                }

        // dp[state]: is it possible to make a square from the state.
        vector<bool> dp(all + 1, false);
        dp[0] = true;
        for(int i = 1; i <= all; i ++)
            for(int j = 0; j < nums.size(); j ++)
                if(i & (1 << j) && dp[i - (1 << j)] && sum[i - (1 << j)] % side + nums[j] <= side){
                    dp[i] = true;
                    break;
                }
        return dp[all];
    }
};


int main() {

    return 0;
}