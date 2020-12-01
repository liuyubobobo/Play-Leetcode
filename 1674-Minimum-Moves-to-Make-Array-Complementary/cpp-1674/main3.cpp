/// Source : https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
/// Author : liuyubobobo
/// Time   : 2020-11-28

#include <iostream>
#include <vector>

using namespace std;


/// Differential Array
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        vector<int> diff(limit * 2 + 2, 0);

        int n = nums.size();
        for(int i = 0; i < n / 2; i ++){
            int A = nums[i], B = nums[n - 1 - i];

            int l = 2, r = 2 * limit;
            diff[l] += 2, diff[r + 1] -= 2;

            l = 1 + min(A, B), r = limit + max(A, B);
            diff[l] += -1, diff[r + 1] -= -1;

            l = A + B, r = A + B;
            diff[l] += -1, diff[r + 1] -= -1;
        }

        int res = n, sum = 0;
        for(int i = 2; i <= 2 * limit; i ++){
            sum += diff[i];
            res = min(res, sum);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 4, 3};
    cout << Solution().minMoves(nums1, 4) << endl;
    // 1

    vector<int> nums2 = {1, 2, 2, 1};
    cout << Solution().minMoves(nums2, 2) << endl;
    // 2

    vector<int> nums3 = {1, 2, 1, 2};
    cout << Solution().minMoves(nums3, 2) << endl;
    // 0

    vector<int> nums4 = {3,1,2,1,2,3,3,1,2,3,2,2,1,2,3,3,3,1,1,2,3,2,1,1,2,3,3,3,1,3,3,1,1,2,2,2,2,2,1,3,1,2,2,2};
    cout << Solution().minMoves(nums4, 3) << endl;
    // 13

    return 0;
}