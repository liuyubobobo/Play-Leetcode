/// Source : https://leetcode.com/problems/rotate-array/description/
/// Author : liuyubobobo
/// Time   : 2018-08-10

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/// Using O(1) Space but O(n^2) operations
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        while(k --){
            int t = nums.back();
            for(int i = (int)nums.size() - 2; i >= 0; i --)
                nums[i + 1] = nums[i];
            nums[0] = t;
        }
        return;
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

    return 0;
}