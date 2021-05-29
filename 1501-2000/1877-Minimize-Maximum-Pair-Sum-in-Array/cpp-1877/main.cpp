/// Source : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
/// Author : liuyubobobo
/// Time   : 2021-05-28

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int minPairSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int res = nums[0] + nums.back();
        for(int i = 1; i < (n >> 1); i ++)
            res = max(res, nums[i] + nums[n - 1 - i]);
        return res;
    }
};


int main() {

    return 0;
}
