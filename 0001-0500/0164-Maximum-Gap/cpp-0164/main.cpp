/// Source : https://leetcode.com/problems/maximum-gap/
/// Author : liuyubobobo
/// Time   : 2021-03-04

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumGap(vector<int>& nums) {

        if(nums.size() < 2) return 0;

        sort(nums.begin(), nums.end());
        int res = INT_MIN;
        for(int i = 1; i < nums.size(); i ++)
            res = max(res, nums[i] - nums[i - 1]);
        return res;
    }
};


int main() {

    return 0;
}
