/// Source : https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
/// Author : liuyubobobo
/// Time   : 2021-05-19

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int res = 0;
        for(int i = 0, j = 0; i < nums1.size(); i ++){

            while(j + 1 < nums2.size() && nums2[j + 1] >= nums1[i]) j ++;
            res = max(res, max(0, j - i));
        }
        return res;
    }
};


int main() {

    vector<int> nums11 = {55, 30, 5, 4, 2}, nums12 = {100, 20, 10, 10, 5};
    cout << Solution().maxDistance(nums11, nums12) << endl;
    // 2

    vector<int> nums21 = {2, 2, 2}, nums22 = {10, 10, 1};
    cout << Solution().maxDistance(nums21, nums22) << endl;
    // 1

    vector<int> nums31 = {30, 29, 19, 5}, nums32 = {25, 25, 25, 25, 25};
    cout << Solution().maxDistance(nums31, nums32) << endl;
    // 2

    vector<int> nums41 = {5, 4}, nums42 = {3, 2};
    cout << Solution().maxDistance(nums41, nums42) << endl;
    // 0

    return 0;
}
