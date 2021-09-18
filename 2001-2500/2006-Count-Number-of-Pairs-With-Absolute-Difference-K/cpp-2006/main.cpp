/// Source : https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
/// Author : liuyubobobo
/// Time   : 2021-09-18

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {

        int res = 0;
        for(int i = 0; i < nums.size(); i ++)
            for(int j = i + 1; j < nums.size(); j ++)
                res += abs(nums[i] - nums[j]) == k;
        return res;
    }
};


int main() {

    return 0;
}
