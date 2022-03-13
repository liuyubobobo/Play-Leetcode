/// Source : https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/
/// Author : liuyubobobo
/// Time   : 2022-03-12

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {

        int n = nums.size();

        if(k == 0) return n > 0 ? nums[0] : -1;
        if(k == 1) return n == 1 ? -1 : nums[1];

        int res = -1, left_op = k, can_add_max = -1;
        for(int i = 0; i < min(k, n); i ++){
            left_op --;

            can_add_max = max(can_add_max, nums[i]);

            if(i + 1 < n && left_op % 2 == 0)
                res = max(res, nums[i + 1]);

            if(left_op && (left_op % 2 || i))
                res = max(res, can_add_max);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {5,2,2,4,0,6};
    cout << Solution().maximumTop(nums1, 4) << '\n';
    // 5

    vector<int> nums2 = {2};
    cout << Solution().maximumTop(nums2, 1) << '\n';
    // -1

    vector<int> nums3 = {31,15,92,84,19,92,55};
    cout << Solution().maximumTop(nums3, 4) << '\n';
    // 92

    vector<int> nums4 = {55,39,99,57,82,48,39,91,82,68,86,4,64,38,73,40,51,66,58,44,55,6,100,6,49,91,34,87,42,22,77,74,31,67,15,99,57,21,61,79,93,98,29,9,34,51,89,67,83,49,2,17,14,29,73,7,41,64,93,83,21,89,66,100,38,45,27,31,25,16,78,32,74,21,48,99,77,65,8,47,93,67};
    cout << Solution().maximumTop(nums4, 40) << '\n';
    // 100

    vector<int> nums5 = {52,98,7,10,27,1,33,17,14,70,79,41,37,83,58,69,52,14,66,7,36,32,39,69,65,64,45,90,34,68,44,51,36,49,71,54,63,76,73,76,67,26,54,76,89,92,89,69,26,55,93,89,15,3,54,91,21,93,78,29,79,59,14,80,70,29,5,80,93,69,29,22,3,6,2,36,31,3,22,96,32,25,97,82,78,10,83,46,98,30,1,93,89};
    cout << Solution().maximumTop(nums5, 27) << '\n';
    // 98

    vector<int> nums6 = {91,98,17,79,15,55,47,86,4,5,17,79,68,60,60,31,72,85,25,77,8,78,40,96,76,69,95,2,42,87,48,72,45,25,40,60,21,91,32,79,2,87,80,97,82,94,69,43,18,19,21,36,44,81,99};
    cout << Solution().maximumTop(nums6, 2) << '\n';
    // 91

    vector<int> nums7 = {4,6,1,0,6,2,4};
    cout << Solution().maximumTop(nums7, 0) << '\n';
    // 4

    return 0;
}
