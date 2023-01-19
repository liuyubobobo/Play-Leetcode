/// Source : https://leetcode.com/problems/count-the-number-of-good-subsequences/description/
/// Author : liuyubobobo
/// Time   : 2023-01-19

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


/// Math
/// Time Complexity: O(n)
/// Space Complexity: O(maxn)
class Solution {

private:
    const int MAXN = 1e4;
    const long long MOD = 1e9 + 7;
    vector<long long> fac, ifac;

public:
    Solution() : fac(MAXN + 1, 1), ifac(MAXN + 1){
        for(int i = 2; i <= MAXN; i ++) fac[i] = fac[i - 1] * i % MOD;
        for(int i = 0; i <= MAXN; i ++) ifac[i] = quick_pow(fac[i], MOD - 2);
    }

    int countGoodSubsequences(string s) {

        int n = s.size();

        vector<int> f(26, 0);
        for(char c: s) f[c - 'a'] ++;

        vector<int> a;
        for(int e: f) if(e) a.push_back(e);
        int maxf = *max_element(a.begin(), a.end());

        long long total = 0;
        for(int i = 1; i <= maxf; i ++){
            long long tres = 1;
            for(int e: a) tres = tres * (C(e, i) + C(e, 0)) % MOD;
            tres = (tres - 1 + MOD) % MOD;
            total += tres;
        }
        return total % MOD;
    }

private:
    long long C(int n, int r){
        if(r > n) return 0;
        return fac[n] * ifac[r] % MOD * ifac[n - r] % MOD;
    }

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

    cout << Solution().countGoodSubsequences("aabb") << '\n';
    // 11

    cout << Solution().countGoodSubsequences("leet") << '\n';
    // 12

    cout << Solution().countGoodSubsequences("abcd") << '\n';
    // 15

    return 0;
}
