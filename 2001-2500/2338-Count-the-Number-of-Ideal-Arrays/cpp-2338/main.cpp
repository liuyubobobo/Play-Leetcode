/// Source : https://leetcode.com/problems/count-the-number-of-ideal-arrays/
/// Author : liuyubobobo
/// Time   : 2022-07-10

#include <iostream>
#include <vector>

using namespace std;


/// Backtrack + Math
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;
    vector<long long> fac, ifac;

public:
    Solution(): fac(1e4 + 1, 1), ifac(1e4 + 1){}

    int idealArrays(int n, int maxValue) {

        for(int i = 1; i <= n; i ++)
            fac[i] = fac[i - 1] * i % MOD;
        for(int i = 0; i <= n; i ++)
            ifac[i] = quick_pow(fac[i], MOD - 2);

        vector<int> seq;
        return go(seq, n, maxValue);
    }

private:
    long long go(vector<int>& seq, int n, int maxValue){

        long long res = 0;
        if(seq.empty()){
            for(int i = 1; i <= maxValue; i ++){
                seq.push_back(i);
                res += go(seq, n, maxValue);
                seq.pop_back();
            }
            return res % MOD;
        }

        int k = seq.size() - 1;
        res += fac[n - 1] * ifac[k] % MOD * ifac[n - 1 - k] % MOD;

        if(seq.size() == n) return res;

        for(int d = 2; seq.back() * d <= maxValue; d ++){
            seq.push_back(seq.back() * d);
            res += go(seq, n, maxValue);
            seq.pop_back();
        }
        return res % MOD;
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

    cout << Solution().idealArrays(2, 5) << '\n';
    // 10

    cout << Solution().idealArrays(5, 3) << '\n';
    // 11

    cout << Solution().idealArrays(5878, 2900) << '\n';
    // 465040898

    cout << Solution().idealArrays(1e4, 1e4) << '\n';
    // 22940607

    return 0;
}
