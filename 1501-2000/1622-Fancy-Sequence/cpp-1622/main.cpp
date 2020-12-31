/// Source : https://leetcode.com/problems/fancy-sequence/
/// Author : liuyubobobo
/// Time   : 2020-10-18

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// See here for reference: https://leetcode.com/problems/fancy-sequence/discuss/898861/C%2B%2B-solution-beats-100-Math-Solution
/// Time Complexity: all operations: O(1)
/// Space Complexity: O(|num|)
class Fancy {

private:
    const long long MOD = 1e9 + 7;
    vector<long long> num;
    long long add = 0ll, mul = 1ll;

public:
    Fancy(){}

    void append(int val) {
        num.push_back((val - add + MOD) % MOD * mypow(mul, MOD - 2) % MOD);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }

    int getIndex(int idx) {
        if(idx >= 0 && idx < num.size())
            return (num[idx] * mul % MOD + add) % MOD;
        return -1;
    }

private:
    long long mypow(long long x, int n){
        if(n == 0) return 1ll;
        if(n == 1) return x;
        long long t = mypow(x, n / 2);
        long long res = t * t % MOD;
        if(n & 1) res = res * x % MOD;
        return res;
    }
};


int main() {

    return 0;
}
