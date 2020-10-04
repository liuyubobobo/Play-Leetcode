/// Source : https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
/// Author : liuyubobobo
/// Time   : 2020-10-04

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int specialArray(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        for(int x = 0; x <= nums.size(); x ++){
            vector<int>::iterator iter = lower_bound(nums.begin(), nums.end(), x);
            if(nums.end() - iter == x) return x;
        }
        return -1;
    }
};


int main() {

    return 0;
}
