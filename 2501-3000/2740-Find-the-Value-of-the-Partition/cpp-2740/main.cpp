/// Source : https://leetcode.com/problems/find-the-value-of-the-partition/description/
/// Author : liuyubobobo
/// Time   : 2023-06-18

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int res = INT_MAX;
        for(int i = 1; i < nums.size(); i ++)
            res = min(res, nums[i] - nums[i - 1]);
        return res;
    }
};


int main() {

    return 0;
}
