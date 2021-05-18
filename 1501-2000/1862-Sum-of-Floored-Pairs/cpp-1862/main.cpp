/// Source : https://leetcode.com/problems/sum-of-floored-pairs/
/// Author : liuyubobobo
/// Time   : 2021-05-17

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Presum
/// Time Complexity: O(n + maxv * log(maxv))
/// Space Complexity: O(maxv)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int sumOfFlooredPairs(vector<int>& nums) {

        int maxv = *max_element(nums.begin(), nums.end());
        vector<int> presum(maxv + 1, 0);
        for(int e: nums) presum[e] ++;
        for(int i = 1; i <= maxv; i ++) presum[i] += presum[i - 1];

        long long res = 0ll;
        for(int e = 1; e <= maxv; e ++)
            if(presum[e] - presum[e - 1]){

                for(int k = 1; k * e <= maxv; k ++)
                    // [k * e, (k + 1) * e - 1]
                    res += (long long)(presum[e] - presum[e - 1]) * k *
                           (((k + 1) * e - 1 <= maxv ? presum[(k + 1) * e - 1] : presum.back()) - presum[k * e - 1]);
            }

        return res % MOD;
    }
};


int main() {

    vector<int> nums1 = {2, 5, 9};
    cout << Solution().sumOfFlooredPairs(nums1) << endl;
    // 10

    vector<int> nums2 = {7, 7, 7, 7, 7, 7, 7};
    cout << Solution().sumOfFlooredPairs(nums2) << endl;
    // 49

    return 0;
}
