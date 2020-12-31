/// Source : https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
/// Author : liuyubobobo
/// Time   : 2020-10-18

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics: C(n + k - 1, 2k)
/// See here for proof: https://leetcode-cn.com/problems/number-of-sets-of-k-non-overlapping-line-segments/solution/da-xiao-wei-k-de-bu-zhong-die-xian-duan-de-shu-mu-/
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int numberOfSets(int n, int k) {

        long long a = fac(n + k - 1);
        long long b = fac(2 * k) * fac(n - k - 1) % MOD;
        return a * mypow(b, MOD - 2) % MOD;
    }

private:
    long long mypow(long long a, int n){

        if(n == 0) return 1ll;
        if(n == 1) return a;
        long long t = mypow(a, n / 2);
        long long res = t * t % MOD;
        if(n & 1) res = res * a % MOD;
        return res;
    }

    long long fac(long long n){

        long long res = 1ll;
        for(long long i = 1; i <= n; i ++)
            res = res * i % MOD;
        return res;
    }
};


int main() {

    cout << Solution().numberOfSets(4, 2) << endl;
    // 5

    cout << Solution().numberOfSets(3, 1) << endl;
    // 3

    cout << Solution().numberOfSets(30, 7) << endl;
    // 796297179

    cout << Solution().numberOfSets(31, 26) << endl;
    // 367290

    return 0;
}
