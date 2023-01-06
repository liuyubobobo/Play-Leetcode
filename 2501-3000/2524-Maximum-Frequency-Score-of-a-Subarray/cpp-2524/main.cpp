/// Source : https://leetcode.com/problems/maximum-frequency-score-of-a-subarray/description/
/// Author : liuyubobobo
/// Time   : 2022-01-06

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window
/// Time Complexity: O(maxv + nlog(maxv))
/// Space Compelxity: O(maxv)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int maxFrequencyScore(vector<int>& nums, int k) {

        int maxv = *max_element(nums.begin(), nums.end());
        vector<int> f(maxv + 1, 0);
        for(int i = 0; i + 1 < k; i ++) f[nums[i]] ++;

        long long cur = 0;
        for(int i = 0; i <= maxv; i ++)
            if(f[i]) cur += quick_pow(i, f[i]), cur %= MOD;

        long long res = 0;
        for(int i = k - 1; i < nums.size(); i ++){
            int num = nums[i];
            if(f[num]){cur -= quick_pow(num, f[num]); cur = (cur + MOD) % MOD;}
            f[num] ++;
            cur += quick_pow(num, f[num]); cur %= MOD;

            res = max(res, cur);

            num = nums[i - (k - 1)];
            cur -= quick_pow(num, f[num]); cur = (cur + MOD) % MOD;
            f[num] --;
            if(f[num]){cur += quick_pow(num, f[num]); cur %= MOD;}
        }
        return res;
    }

private:
    long long quick_pow(long long a, long long k) {
        long long res = 1ll;
        while (k) {
            if (k & 1) res = res * a % MOD;
            a = a * a % MOD;
            k >>= 1;
        }
        return res % MOD;
    }
};

int main() {

    return 0;
}
