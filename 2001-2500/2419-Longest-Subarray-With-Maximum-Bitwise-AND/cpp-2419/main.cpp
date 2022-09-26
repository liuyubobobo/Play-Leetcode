/// Source : https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
/// Author : liuyubobobo
/// Time   : 2022-09-26

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Split
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int target = *max_element(nums.begin(), nums.end());

        int res = 1;
        for(int start = 0, i = 1; i <= nums.size(); i ++){
            if(i == nums.size() || nums[i] != nums[start]){
                if(nums[start] == target) res = max(res, i - start);
                start = i;
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
