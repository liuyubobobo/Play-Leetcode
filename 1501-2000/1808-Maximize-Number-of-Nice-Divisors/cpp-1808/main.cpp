/// Source : https://leetcode.com/problems/maximize-number-of-nice-divisors/
/// Author : liuyubobobo
/// Time   : 2021-03-27

#include <iostream>

using namespace std;


/// Mathematics
/// Time Complexity: O(log(primeFactors))
/// Space Complexity: O(log(primeFactors))
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int maxNiceDivisors(int primeFactors) {

        if(primeFactors <= 3) return  primeFactors;

        int n3 = primeFactors / 3;
        if(primeFactors % 3 == 1) n3 --;

        long long res = mypow(3ll, n3);
        if(primeFactors % 3 == 1) res = res * 4ll % MOD;
        if(primeFactors % 3 == 2) res = res * 2ll % MOD;
        return res;
    }

private:
    long long mypow(long long a, int k){

        if(k == 0) return 1ll;

        long long t = mypow(a, k / 2);
        long long res = t * t % MOD;
        if(k % 2) res = res * a % MOD;
        return res;
    }
};


int main() {

    cout << Solution().maxNiceDivisors(5) << endl;
    // 6

    cout << Solution().maxNiceDivisors(8) << endl;
    // 18

    return 0;
}
