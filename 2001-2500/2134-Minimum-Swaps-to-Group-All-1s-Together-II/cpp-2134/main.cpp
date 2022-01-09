/// Source : https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
/// Author : liuyubobobo
/// Time   : 2022-01-08

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int n = nums.size();

        vector<int> A = nums;
        for(int e: nums) A.push_back(e);

        vector<int> presum(2 * n + 1, 0);
        for(int i = 0; i < A.size(); i ++)
            presum[i + 1] = presum[i] + A[i];

        int k = accumulate(nums.begin(), nums.end(), 0);
        int res = INT_MAX;
        for(int i = 0; i < n; i ++)
            res = min(res, k - (presum[i + k] - presum[i]));
        return res;
    }
};


int main() {

    vector<int> nums1 = {0, 1, 0, 1, 1, 0, 0};
    cout << Solution().minSwaps(nums1) << endl;
    // 1

    vector<int> nums2 = {0,1,1,1,0,0,1,1,0};
    cout << Solution().minSwaps(nums2) << endl;
    // 2

    vector<int> nums3 = {1,1,0,0,1};
    cout << Solution().minSwaps(nums3) << endl;
    // 0

    return 0;
}
