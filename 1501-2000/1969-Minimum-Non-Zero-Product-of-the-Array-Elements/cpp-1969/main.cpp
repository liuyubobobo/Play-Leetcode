/// Source : https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/
/// Author : liuyubobobo
/// Time   : 2021-08-14

#include <iostream>

using namespace std;


/// Quick Power
/// Time Complexity: O(p)
/// Space Complexity: O(p)
class Solution {
public:
    int minNonZeroProduct(int p) {

        if(p == 1) return 1;

        const long long MOD = 1e9 + 7;

        long long res = ((((long long)1) << p) - 1ll) % MOD;

        long long a = ((((long long)1) << p) - 2ll) % MOD;
        long long power = (((long long)1) << (p - 1)) - 1ll;
        res *= quick_pow(a, power, MOD);
        res %= MOD;

        return res;
    }

private:
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

    cout << Solution().minNonZeroProduct(1) << endl;
    // 1

    cout << Solution().minNonZeroProduct(2) << endl;
    // 6

    cout << Solution().minNonZeroProduct(3) << endl;
    // 1512

    cout << Solution().minNonZeroProduct(35) << endl;
    // 1512

    return 0;
}
