/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-15

#include <iostream>
#include <vector>

using namespace std;

/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i = 0 ; i < nums.size() ; i ++)
            for(int j = i + 1 ; j < nums.size() ; j ++)
                if(nums[i] + nums[j] == target)
                    return {i, j};

        throw invalid_argument("the input has no solution");
    }
};


int main() {

    vector<int> nums = {0,4,3,0};
    int target = 0;
    printVec(Solution().twoSum(nums, target));

    return 0;
}