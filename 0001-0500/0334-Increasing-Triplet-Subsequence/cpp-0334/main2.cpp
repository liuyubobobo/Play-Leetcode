/// Source : https://leetcode.com/problems/increasing-triplet-subsequence/
/// Author : liuyubobobo
/// Time   : 2020-12-18

#include <iostream>
#include <vector>

using namespace std;


/// LIS - but only for 3 elements
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int a = nums[0], b = INT_MAX;
        for(int i = 1; i < nums.size(); i ++){
            if(nums[i] > b) return true;
            else if(nums[i] <= b && nums[i] > a) b = nums[i];
            else{
                assert(nums[i] <= a);
                a = nums[i];
            }
        }
        return false;
    }
};


int main() {

    return 0;
}
