/// Source : https://leetcode.com/problems/find-peak-element/
/// Author : liuyubobobo
/// Time   : 2021-06-15

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        if(nums.size() == 1) return 0;

        return binary_search(nums, 0, nums.size() - 1);
    }

private:
    int binary_search(const vector<int>& nums, int l, int r){

        if(l == r) return l;

        int mid = (l + r) / 2;
        if(mid + 1 <= r && nums[mid] > nums[mid + 1])
            return binary_search(nums, l, mid);
        return binary_search(nums, mid + 1, r);
    }
};


int main() {

    return 0;
}
