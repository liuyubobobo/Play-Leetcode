/// Source : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
/// Author : liuyubobobo
/// Time   : 2021-05-19

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int a = nums[nums.size() / 2];

        int res = 0;
        for(int e: nums) res += abs(e - a);
        return res;
    }
};


int main() {

    return 0;
}
