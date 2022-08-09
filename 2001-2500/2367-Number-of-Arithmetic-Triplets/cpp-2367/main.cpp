/// Source : https://leetcode.com/problems/number-of-arithmetic-triplets/
/// Author : liuyubobobo
/// Time   : 2022-08-07

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^3)
/// Space Complexity: O(1)
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {

        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                for(int k = j + 1; k < n; k ++)
                    res += (nums[k] - nums[j] == diff && nums[j] - nums[i] == diff);
        return res;
    }
};


int main() {

    return 0;
}
