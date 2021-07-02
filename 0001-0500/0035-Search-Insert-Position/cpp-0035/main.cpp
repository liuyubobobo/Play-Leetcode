/// Source : https://leetcode.com/problems/search-insert-position/
/// Author : liuyubobobo
/// Time   : 2021-07-02

#include <iostream>
#include <vector>

using namespace std;


/// lower bound
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};


int main() {

    return 0;
}
