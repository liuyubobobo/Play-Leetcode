/// Source : https://leetcode.com/problems/find-target-indices-after-sorting-array/
/// Author : liuyubobobo
/// Time   : 2021-11-27

#include <iostream>
#include <vector>

using namespace std;


/// Sorting + Brute Force
/// Time Complexity: O(nlogn + n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<int> res;
        for(int i = 0; i < nums.size(); i ++)
            if(nums[i] == target) res.push_back(i);
        return res;
    }
};


int main() {

    return 0;
}
