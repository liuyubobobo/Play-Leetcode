/// Source : https://leetcode.com/problems/k-divisible-elements-subarrays/
/// Author : liuyubobobo
/// Time   : 2022-05-01

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;


/// Hash
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {

private:
    const unsigned long long B = 13331;

public:
    int countDistinct(vector<int>& nums, int k, int p) {

        int n = nums.size();
        vector<int> k_divisible(n, 0);
        for(int i = 0; i < n; i ++) k_divisible[i] = (nums[i] % p == 0);

        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + k_divisible[i];

        vector<set<unsigned long long>> res(k + 1);
        for(int l = 0; l < n; l ++)
            for(int r = l; r < n; r ++){

                int t = presum[r + 1] - presum[l];
                if(t <= k) res[t].insert(vector_to_hash(nums, l, r));
                else break;
            }

        int ret = 0;
        for(const set<unsigned long long>& s: res) ret += s.size();
        return ret;
    }

private:
    unsigned long long vector_to_hash(const vector<int>& nums, int l, int r){
        unsigned long long res = 0;
        for(int i = l; i <= r; i ++) res = res * B + nums[i];
        return res;
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
