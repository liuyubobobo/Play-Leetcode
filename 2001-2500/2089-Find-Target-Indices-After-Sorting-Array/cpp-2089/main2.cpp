/// Source : https://leetcode.com/problems/find-target-indices-after-sorting-array/
/// Author : liuyubobobo
/// Time   : 2021-11-27

#include <iostream>
#include <vector>

using namespace std;


/// Sorting + Binary Search
/// Time Complexity: O(nlogn + n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        vector<int> res;
        for(int i = l; i < r; i ++) res.push_back(i);
        return res;
    }
};


int main() {

    return 0;
}
