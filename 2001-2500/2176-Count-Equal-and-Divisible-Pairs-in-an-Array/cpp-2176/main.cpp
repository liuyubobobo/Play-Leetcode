/// Source : https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/
/// Author : liuyubobobo
/// Time   : 2022-02-19

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {

        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                if(nums[i] == nums[j] && (i * j) % k == 0) res ++;
        return res;
    }
};


int main() {

    return 0;
}
