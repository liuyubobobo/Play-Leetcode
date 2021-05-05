/// Source : https://leetcode.com/problems/jump-game/
/// Author : liuyubobobo
/// Time   : 2021-05-05

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        for(int i = 1; i < n; i ++)
            for(int j = i - 1; j >= 0; j --)
                if(dp[j] && j + nums[j] >= i){
                    dp[i] = true;
                    break;
                }
        return dp.back();
    }
};


int main() {

    return 0;
}
