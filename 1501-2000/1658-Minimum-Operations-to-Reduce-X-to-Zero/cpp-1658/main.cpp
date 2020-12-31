/// Source : https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
/// Author : liuyubobobo
/// Time   : 2020-11-14

#include <iostream>
#include <vector>

using namespace std;


/// Presum and Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();
        vector<int> presum(n + 1, 0);

        int res = INT_MAX;
        for(int i = 0; i < n; i ++) {
            presum[i + 1] = presum[i] + nums[i];
            if(presum[i + 1] == x) res = min(res, i + 1);
        }

        int cur = 0;
        for(int i = n - 1; i >= 0; i --){
            cur += nums[i];
            vector<int>::iterator iter = lower_bound(presum.begin(), presum.begin() + i, x - cur);
            if(iter != presum.begin() + i && *iter == x - cur)
                res = min(res, n - i + (int)(iter - presum.begin()));
        }
        return res == INT_MAX ? -1 : res;
    }
};


int main() {

    vector<int> nums1 = {1, 1, 4, 2, 3};
    cout << Solution().minOperations(nums1, 5) << endl;
    // 2

    vector<int> nums2 = {5, 6, 7, 8, 9};
    cout << Solution().minOperations(nums2, 4) << endl;
    // -1

    vector<int> nums3 = {3,2,20,1,1,3};
    cout << Solution().minOperations(nums3, 10) << endl;
    // 5

    return 0;
}
