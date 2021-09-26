/// Source : https://leetcode.com/problems/maximum-difference-between-increasing-elements/
/// Author : liuyubobobo
/// Time   : 2021-09-25

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int n = nums.size(), res = -1;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                if(nums[i] < nums[j])
                    res = max(res, nums[j] - nums[i]);
        return res;
    }
};


int main() {

    return 0;
}
