/// Source : https://leetcode.com/problems/check-if-an-array-is-consecutive/
/// Author : liuyubobobo
/// Time   : 2022-04-08

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    bool isConsecutive(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i ++)
            if(nums[i] != nums[0] + i) return false;
        return true;
    }
};


int main() {

    return 0;
}
