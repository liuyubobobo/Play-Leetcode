/// Source : https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/description/
/// Author : liuyubobobo
/// Time   : 2023-07-10

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^3)
/// Space Complexity: O(1)
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {

        int n = nums.size(), res = 0;
        for(int l = 0; l < n; l ++){
            if(nums[l] % 2 || nums[l] > threshold) continue;

            bool ok = true;
            for(int r = l; r < n && ok; r ++){
                for(int i = l + 1; i <= r && ok; i ++)
                    if(nums[i] % 2 == nums[i - 1] % 2 || nums[i] > threshold)
                        ok = false;
                if(ok) res = max(res, r - l + 1);
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
