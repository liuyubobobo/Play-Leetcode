/// Source : https://leetcode.com/problems/count-good-numbers/
/// Author : liuyubobobo
/// Time   : 2021-07-03

#include <iostream>
#include <vector>

using namespace std;


/// Fast Power
/// Time Complexity: O(logn)
/// Space Complexity: O(logn)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int countGoodNumbers(long long n) {

        long long evenpos = (n + 1ll) / 2ll, oddpos = n - evenpos;

        return mypow(5, evenpos) * mypow(4, oddpos) % MOD;
    }

private:
    long long mypow(long long a, long long k){

        if(k == 0ll) return 1ll;

        long long tres = mypow(a, k / 2ll);
        long long res = tres * tres % MOD;
        if(k % 2ll == 1ll) res = res * a % MOD;
        return res;
    }
};


int main() {

    cout << Solution().countGoodNumbers(1ll) << endl;
    // 5

    cout << Solution().countGoodNumbers(4ll) << endl;
    // 400

    cout << Solution().countGoodNumbers(50ll) << endl;
    // 564908303

    cout << Solution().countGoodNumbers(2ll) << endl;
    // 20

    return 0;
}
