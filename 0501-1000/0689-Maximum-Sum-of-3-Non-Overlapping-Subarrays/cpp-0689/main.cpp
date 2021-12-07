/// Source : https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
/// Author : liuyubobobo
/// Time   : 2021-12-07

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        vector<long long> presum(n + 1, 0ll);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + nums[i];

        vector<long long> max1(n, presum[n] - presum[n - k]);
        vector<int> max1_index(n, n - k);
        for(int i = n - k - 1; i >= 0; i --){
            max1[i] = max1[i + 1], max1_index[i] = max1_index[i + 1];
            if(presum[i + k] - presum[i] >= max1[i + 1])
                max1[i] = presum[i + k] - presum[i],
                max1_index[i] = i;
        }

        vector<long long> max2(n, presum[n] - presum[n - 2 * k]);
        vector<pair<int, int>> max2_index(n, {n - 2 * k, n - k});
        for(int i = n - 2 * k - 1; i >= 0; i --){
            max2[i] = max2[i + 1], max2_index[i] = max2_index[i + 1];
            if(presum[i + k] - presum[i] + max1[i + k] >= max2[i + 1])
                max2[i] = presum[i + k] - presum[i] + max1[i + k],
                max2_index[i] = {i, max1_index[i + k]};
        }

        long long cur_max = presum[n] - presum[n - 3 * k];
        vector<int> max3_index = {n - 3 * k, n - 2 * k, n - k};
        for(int i = n - 3 * k - 1; i >= 0; i --){
            if(presum[i + k] - presum[i] + max2[i + k] >= cur_max)
                cur_max = presum[i + k] - presum[i] + max2[i + k],
                max3_index = {i, max2_index[i + k].first, max2_index[i + k].second};
        }
        return max3_index;
    };
};


int main() {

    return 0;
}
