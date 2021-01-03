/// Source : https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
/// Author : liuyubobobo
/// Time   : 2021-01-02

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Only use presum and built-in binary search functions
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int waysToSplit(vector<int>& nums) {

        int n = nums.size();

        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + nums[i];

        int res = 0;
        for(int i = 0; i + 2 < n; i ++){
            int lsum1 = presum[i + 1];
            vector<int>::iterator iter1 = lower_bound(presum.begin() + (i + 2), presum.end() - 1, lsum1 + lsum1);
            int a = iter1 - presum.begin();

            int sum = presum.back() - lsum1;
            int lsum2 = sum / 2;

            vector<int>::iterator iter2 = upper_bound(presum.begin() + a, presum.end() - 1, lsum1 + lsum2);
            int b = iter2 - presum.begin();
            res = (res + (b - a)) % MOD;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 1, 1};
    cout << Solution().waysToSplit(nums1) << endl;
    // 1

    vector<int> nums2 = {1, 2, 2, 2, 5, 0};
    cout << Solution().waysToSplit(nums2) << endl;
    // 3

    vector<int> nums3 = {3, 2, 1};
    cout << Solution().waysToSplit(nums3) << endl;
    // 0

    vector<int> nums4 = {0, 3, 3};
    cout << Solution().waysToSplit(nums4) << endl;
    // 1

    vector<int> nums5(1e5, 0);
    cout << Solution().waysToSplit(nums5) << endl;
    // 999849973

    return 0;
}
