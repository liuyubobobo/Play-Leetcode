/// Source : https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/description/
/// Author : liuyubobobo
/// Time   : 2023-01-28

#include <iostream>

using namespace std;


/// Math
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int monkeyMove(int n) {
        return (quick_pow(2, n) - 2 + MOD) % MOD;
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
