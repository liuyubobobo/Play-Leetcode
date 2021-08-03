/// Source : https://leetcode.com/problems/single-element-in-a-sorted-array/
/// Author : liuyubobobo
/// Time   : 2021-08-03

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        nums.push_back(-1);

        int n = nums.size() / 2;
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[2 * mid] != nums[2 * mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return nums[2 * l];
    }
};


int main() {

    return 0;
}
