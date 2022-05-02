/// Source : https://leetcode.com/problems/k-divisible-elements-subarrays/
/// Author : liuyubobobo
/// Time   : 2022-04-30

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^3)
/// Space Compelxity: O(n^3)
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {

        int n = nums.size();
        vector<int> k_divisible(n, 0);
        for(int i = 0; i < n; i ++) k_divisible[i] = (nums[i] % p == 0);

        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + k_divisible[i];

        vector<set<vector<int>>> res(k + 1);
        for(int l = 0; l < n; l ++)
            for(int r = l; r < n; r ++){

                int t = presum[r + 1] - presum[l];
                if(t <= k)
                    res[t].insert(vector<int>(nums.begin() + l, nums.begin() + (r + 1)));
                else break;
            }

        int ret = 0;
        for(const set<vector<int>>& s: res) ret += s.size();
        return ret;
    }
};


int main() {

    vector<int> nums1 = {2, 3, 3, 2, 2};
    cout << Solution().countDistinct(nums1, 2, 2) << '\n';
    // 11

    vector<int> nums2 = {1, 2, 3, 4};
    cout << Solution().countDistinct(nums2, 4, 1) << '\n';
    // 10

    return 0;
}
