/// Source : https://leetcode.com/problems/sum-of-subarray-ranges/
/// Author : liuyubobobo
/// Time   : 2021-12-11

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();
        long long res = 0;
        for(int l = 0; l < n; l ++){
            int minv = nums[l], maxv = nums[l];
            for(int r = l + 1; r < n; r ++){
                minv = min(minv, nums[r]), maxv = max(maxv, nums[r]);
                res += (maxv - minv);
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
