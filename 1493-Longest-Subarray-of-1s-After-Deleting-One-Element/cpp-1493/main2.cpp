/// Source : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
/// Author : liuyubobobo
/// Time   : 2020-06-27

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int res = 0, l = 0, r = -1, k = 0;
        while(l < nums.size()){
            if(k == 2 || r + 1 == nums.size()){
                k -= !nums[l ++];
            }
            else{
                if(r + 1 < nums.size())
                    k += !nums[++r];
                res = max(res, r - l + 1 - k);
            }
        }
        return res == nums.size() ? res - 1 : res;
    }
};


int main() {

    return 0;
}
