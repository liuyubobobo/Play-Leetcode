/// Source : https://leetcode.com/problems/the-number-of-good-subsets/
/// Author : liuyubobobo
/// Time   : 2021-09-05

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Memoization
/// Time Complexity: O(19 * 2^11)
/// Space Complexity: O(19 * 2^11)
class Solution {

private:
    vector<int> primes = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    const long long MOD = 1e9 + 7;

public:
    int numberOfGoodSubsets(vector<int>& nums) {

        int maxv = *max_element(nums.begin(), nums.end());
        vector<int> num2state(31, 0);
        num2state[1] = 1;
        for(int i = 2; i <= maxv; i ++)
            num2state[i] = get_num_state(i);

        map<int, int> map;
        for(int num: nums)
            if(num2state[num] != -1) map[num] ++;

        vector<pair<int, int>> f;
        for(const pair<int, int>& p: map) f.push_back(p);

        vector<vector<long long>> dp(f.size(), vector<long long>(1 << 11, -1ll));
        return dfs(0, 0, num2state, f, dp);
    }

private:
    long long dfs(int index, int state,
                  const vector<int>& num2state, const vector<pair<int, int>>& f,
                  vector<vector<long long>>& dp){

        if(index == f.size()) return 0;
        if(dp[index][state] != -1ll) return dp[index][state];

        long long res = dfs(index + 1, state, num2state, f, dp);

        if((state & num2state[f[index].first]) == 0){
            long long a = f[index].second, b = dfs(index + 1, state | num2state[f[index].first], num2state, f, dp);

            if(f[index].first != 1) res += a * (b + 1);
            else res += (quick_pow(2ll, a, MOD) - 1 + MOD) % MOD * b;
            res %= MOD;
        }

        return dp[index][state] = res;
    }

    int get_num_state(int num){

        int res = 0;
        for(int i = 1; i < primes.size() && num >= primes[i]; i ++){
            if(num % primes[i] == 0){
                res += (1 << i);
                num /= primes[i];
                if(num % primes[i] == 0) return -1;
            }
        }
        return res;
    }

    long long quick_pow(long long a, long long k, long long MOD) {
        long long res = 1ll;
        while (k > 0) {
            if (k & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            k >>= 1;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 4};
    cout << Solution().numberOfGoodSubsets(nums1) << endl;
    // 6

    vector<int> nums2 = {4, 2, 3, 15};
    cout << Solution().numberOfGoodSubsets(nums2) << endl;
    // 5

    return 0;
}
