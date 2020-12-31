/// Source : https://leetcode.com/problems/running-sum-of-1d-array/
/// Author : liuyubobobo
/// Time   : 2020-06-13

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        vector<int> res(nums.size());
        res[0] = nums[0];
        for(int i = 1; i < nums.size(); i ++)
            res[i] = res[i - 1] + nums[i];
        return res;
    }
};


int main() {

    return 0;
}
