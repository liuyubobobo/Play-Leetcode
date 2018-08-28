/// Source : https://leetcode.com/problems/matchsticks-to-square/description/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;


/// Backtracking
/// Time Complexity: O(4^n)
/// Space Complexity: O(n)
class Solution {
public:
    bool makesquare(vector<int>& nums) {

        if(nums.size() == 0)
            return false;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 4)
            return false;

        int side = sum / 4;
        vector<int> cur = {side, side, side, side};
        return dfs(nums, 0, cur);
    }

private:
    bool dfs(const vector<int>& nums, int index, vector<int>& cur){

        if(index == nums.size()){
            for(int e: cur)
                if(e)
                    return false;
            return true;
        }

        for(int i = 0; i < cur.size() ; i ++)
            if(cur[i] >= nums[index]){
                cur[i] -= nums[index];
                if(dfs(nums, index + 1, cur))
                    return true;
                cur[i] += nums[index];
            }
        return false;
    }
};


int main() {

    return 0;
}