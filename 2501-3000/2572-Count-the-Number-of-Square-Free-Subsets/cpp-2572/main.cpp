/// Source : https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/
/// Author : liuyubobobo
/// Time   : 2023-02-22

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// DP
/// Time Complexity: O(n * 2^10 + 2^20)
/// Space Complexity: O(2^10)
class Solution {

private:
    const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    const int prime_sz = primes.size();
    const long long MOD = 1e9 + 7;

public:
    int squareFreeSubsets(vector<int>& nums) {

        int n = nums.size(), ones = 0;
        vector<int> cnt(1 << prime_sz, 0);
        for(int num: nums){
            if(contain_square_factor(num)) continue;
            if(num == 1){ ones ++; continue;}
            int mask = 0;
            for(int i = 0; i < prime_sz; i ++)
                if(num % primes[i] == 0)
                    mask |= (1 << i);
            cnt[mask] ++;
        }

        vector<long long> dp(1 << prime_sz, 0);
        dp[0] = 1;
        for(int mask = 1; mask < (1 << prime_sz); mask ++) {
            for(int submask = mask; submask >= 1; submask --)
                if((submask & mask) == submask && __builtin_ffs(submask) == __builtin_ffs(mask))
                    dp[mask] += dp[mask - submask] * cnt[submask];
            dp[mask] %= MOD;
        }
        long long res = accumulate(dp.begin(), dp.end(), 0LL) % MOD;

        long long ones_res = 1;
        for(int i = 0; i < ones; i ++) ones_res = ones_res * 2 % MOD;
        return (res * ones_res % MOD - 1 + MOD) % MOD;
    }

private:
    bool contain_square_factor(int num){
        for(int prime: primes)
            if(num % (prime * prime) == 0) return true;
        return false;
    }
};


int main() {

    vector<int> nums1 = {3, 4, 4, 5};
    cout << Solution().squareFreeSubsets(nums1) << endl;
    // 3

    return 0;
}
