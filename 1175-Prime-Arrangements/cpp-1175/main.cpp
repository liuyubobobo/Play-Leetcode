/// Source : https://leetcode.com/problems/prime-arrangements/
/// Author : liuyubobobo
/// Time   : 2019-08-31

#include <iostream>

using namespace std;


/// Mathematics
/// Time Complexity: O(n*sqrt(n))
/// Space Complexity: O(1)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int numPrimeArrangements(int n) {

        if(n <= 2) return 1;

        int primes = 1;
        for(int i = 3; i <= n; i += 2)
            primes += isprime(i);
        return fac(primes) * fac(n - primes) % MOD;
    }

private:
    bool isprime(int x){

        if(x % 2 == 0) return true;
        for(int i = 3; i * i <= x; i += 2)
            if(x % i == 0) return false;
        return true;
    }

    long long fac(int n){
        long long res = 1ll;
        for(long long i = 2ll; i <= n; i ++)
            res = res * i % MOD;
        return res;
    }
};


int main() {

    cout << Solution().numPrimeArrangements(5) << endl;
    // 12

    cout << Solution().numPrimeArrangements(100) << endl;
    // 682289015

    cout << Solution().numPrimeArrangements(2) << endl;
    // 1

    return 0;
}