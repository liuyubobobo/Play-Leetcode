/// Source : https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
/// Author : liuyubobobo
/// Time   : 2021-08-28

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Compleixty: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        if(k == 1) return 0;
        sort(nums.begin(), nums.end());

        int res = INT_MAX;
        for(int i = k - 1; i < nums.size(); i ++)
            res = min(res, nums[i] - nums[i - (k - 1)]);
        return res;
    }
};


int main() {

    return 0;
}
