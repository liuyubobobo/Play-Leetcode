/// Source : https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/
/// Author : liuyubobobo
/// Time   : 2022-09-17

#include <iostream>
#include <vector>

using namespace std;


/// Bitwise + Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    const int L = 30;

public:
    vector<int> smallestSubarrays(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> presum(L, vector<int>(n + 1, 0));
        for(int i = 0; i < n; i ++){
            for(int p = 0; p < L; p ++)
                presum[p][i + 1] = (nums[i] >> p) & 1;
        }

        for(int p = 0; p < L; p ++)
            for(int i = 0; i < n; i ++) presum[p][i + 1] += presum[p][i];

        vector<int> res(n, 1);
        for(int i = 0; i < n; i ++){
            int t = 1;
            for(int p = 0; p < L; p ++){
                if((nums[i] >> p) & 1) continue;
                if(presum[p][i + 1] == presum[p].back()) continue;
                auto iter = lower_bound(presum[p].begin() + (i + 1), presum[p].end(), presum[p][i + 1] + 1);
                int index = iter - presum[p].begin();
                t = max(t, index - (i + 1) + 1);
            }
            res[i] = t;
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<int> nums1 = {1, 0, 2, 1, 3};
    print_vec(Solution().smallestSubarrays(nums1));
    // 3 3 2 2 1

    vector<int> nums2 = {1, 2};
    print_vec(Solution().smallestSubarrays(nums2));
    // 2 1

    return 0;
}
