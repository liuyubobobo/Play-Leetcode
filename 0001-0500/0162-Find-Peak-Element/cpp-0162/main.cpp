/// Source : https://leetcode.com/problems/find-peak-element/
/// Author : liuyubobobo
/// Time   : 2021-06-15

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        if(nums.size() == 1) return 0;

        int n = nums.size();
        if(nums[0] > nums[1]) return 0;
        if(nums[n - 1] > nums[n - 2]) return n - 1;

        for(int i = 1; i + 1 < n; i ++)
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        return -1;
    }
};


int main() {

    return 0;
}
