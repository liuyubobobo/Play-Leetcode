/// Source : https://leetcode.com/problems/running-sum-of-1d-array/
/// Author : liuyubobobo
/// Time   : 2020-06-13

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        for(int i = 1; i < nums.size(); i ++)
            nums[i] += nums[i - 1];
        return nums;
    }
};


int main() {

    return 0;
}
