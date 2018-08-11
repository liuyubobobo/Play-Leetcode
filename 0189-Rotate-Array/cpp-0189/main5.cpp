/// Source : https://leetcode.com/problems/rotate-array/description/
/// Author : liuyubobobo
/// Time   : 2018-08-10

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/// Using Reverse
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

private:
    void reverse(vector<int>& nums, int start, int end){
        for(int i = start, j = end; i < j; i ++, j --)
            swap(nums[i], nums[j]);
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    Solution().rotate(nums1, 3);
    print_vec(nums1);
    // 5 6 7 1 2 3 4

    vector<int> nums2 = {1, 2};
    Solution().rotate(nums2, 3);
    print_vec(nums2);
    // 2 1

    vector<int> nums3 = {1, 2};
    Solution().rotate(nums3, 2);
    print_vec(nums3);
    // 1 2

    vector<int> nums4 = {1, 2, 3, 4, 5, 6};
    Solution().rotate(nums4, 2);
    print_vec(nums4);
    // 5 6 1 2 3 4

    return 0;
}