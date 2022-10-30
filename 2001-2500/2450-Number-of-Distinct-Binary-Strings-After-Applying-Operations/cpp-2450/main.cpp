/// Source : https://leetcode.com/problems/number-of-distinct-binary-strings-after-applying-operations/
/// Author : liuyubobobo
/// Time   : 2022-10-30

#include <iostream>

using namespace std;


/// Math
/// Time Complexity: O(log(n - k + 1))
/// Space Complexity: O(log(n - k + 1))
class Solution {
public:
    int countDistinctStrings(string s, int k) {

        int n = s.size();
        return quick_pow(2ll, n - k + 1, 1e9 + 7ll);
    }

private:
    long long quick_pow(long long a, long long k, long long MOD) {
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
