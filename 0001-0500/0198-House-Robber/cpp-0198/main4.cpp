/// Source : https://leetcode.com/problems/house-robber/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

#include <iostream>
#include <vector>

using namespace std;

/// Memory Search
/// Another way to define the states
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    // the max profit for robbing nums[0...i]
    vector<int> memo;

    int tryRob(const vector<int> &nums, int index){

        if(index < 0)
            return 0;

        if(memo[index] != -1)
            return memo[index];

        return memo[index] = max(tryRob(nums, index - 1),
                                 nums[index] + tryRob(nums, index - 2));
    }

public:
    int rob(vector<int>& nums) {

        memo.clear();
        for(int i = 0 ; i < nums.size() ; i ++)
            memo.push_back(-1);
        return tryRob(nums, nums.size() - 1 );
    }
};

int main() {

    int nums[] = {2, 1};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));

    cout << Solution().rob(vec) << endl;

    return 0;
}