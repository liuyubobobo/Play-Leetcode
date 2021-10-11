/// Source : https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
/// Author : liuyubobobo
/// Time   : 2021-10-09

#include <iostream>
#include <vector>

using namespace std;


/// Bit Mask + Binary Search
/// Time Complexity: O(2 ^ (n / 2) * (n / 2))
/// Space Complexity: O(2 ^ (n / 2))
class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int n = nums.size();
        int half = n / 2;

        vector<int> sum1(1 << half, 0);
        for(int state = 1; state < (1 << half); state ++){
            int p = __builtin_ffs(state) - 1;
            sum1[state] = sum1[state - (1 << p)] + nums[p];
        }

        vector<int> sum2(1 << half, 0);
        for(int state = 1; state < (1 << half); state ++){
            int p = __builtin_ffs(state) - 1;
            sum2[state] = sum2[state - (1 << p)] + nums[half + p];
        }

        vector<vector<int>> ones(16);
        for(int state = 0; state < (1 << half); state ++){
            int k = __builtin_popcount(state);
            ones[k].push_back(sum2[state] - sum2[(1 << half) - 1 - state]);
        }
        for(int i = 0; i <= 15; i ++)
            sort(ones[i].begin(), ones[i].end());

        int res = INT_MAX;
        for(int state1 = 0; state1 < (1 << half); state1 ++){
            int k1 = __builtin_popcount(state1);
            int k2 = half - k1;

            int cur = sum1[state1] - sum1[(1 << half) - 1 - state1];
            vector<int>::iterator iter = lower_bound(ones[k2].begin(), ones[k2].end(), -cur);
            if(iter != ones[k2].end())
                res = min(res, abs(cur + *iter));
            if(iter != ones[k2].begin()){
                iter --;
                res = min(res, abs(cur + *iter));
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {3, 9, 7, 3};
    cout << Solution().minimumDifference(nums1) << endl;
    // 2

    vector<int> nums2 = {36, -36};
    cout << Solution().minimumDifference(nums2) << endl;
    // 72

    vector<int> nums3 = {2,-1,0,4,-2,-9};
    cout << Solution().minimumDifference(nums3) << endl;
    // 0

    vector<int> nums4 = {76,8,45,20,74,84,28,1};
    cout << Solution().minimumDifference(nums4) << endl;
    // 2

    return 0;
}
