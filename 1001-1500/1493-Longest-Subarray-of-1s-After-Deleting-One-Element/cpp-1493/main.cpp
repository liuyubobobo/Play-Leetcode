/// Source : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
/// Author : liuyubobobo
/// Time   : 2020-06-27

#include <iostream>
#include <vector>

using namespace std;


/// Split
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        vector<pair<int, int>> ones;
        int start = -1, res = 0;
        for(int i = 0; i <= nums.size(); i ++)
            if(i < nums.size() && nums[i])
                start = start == -1 ? i : start;
            else if(start != -1){
                res = max(res, i - start);
                ones.push_back({start, i});
                start = -1;
            }

        if(ones.size() == 0) return 0;
        if(ones.size() == 1 && ones[0].second - ones[0].first == nums.size()) return nums.size() - 1;

        for(int i = 1; i < ones.size(); i ++)
            if(ones[i - 1].second + 1 == ones[i].first)
                res = max(res, ones[i - 1].second - ones[i - 1].first + ones[i].second - ones[i].first);
        return res;
    }
};


int main() {

    return 0;
}
