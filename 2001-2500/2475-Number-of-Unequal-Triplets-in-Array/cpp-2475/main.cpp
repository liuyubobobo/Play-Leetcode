/// Source : https://leetcode.com/problems/number-of-unequal-triplets-in-array/
/// Author : liuyubobobo
/// Time   : 2022-11-28

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^3)
/// Space Complexity: O(1)
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {

        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                for(int k = j + 1; k < n; k ++)
                    res += (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k]);
        return res;
    }
};


int main() {

    return 0;
}
