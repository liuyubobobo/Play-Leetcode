/// Source : https://leetcode.com/problems/nth-magical-number/description/
/// Author : liuyubobobo
/// Time   : 2018-08-03

#include <iostream>
#include <cassert>

using namespace std;


/// Mathmatically Method
/// Time Complexity: O(log(min(A, B) * N))
/// Space Complexity: O(1)
class Solution {

private:
    long long MOD = (long long)(1e9 + 7);

public:
    int nthMagicalNumber(int N, int A, int B) {

        int lcm = A * B / gcd(A, B);
        int seg = lcm;
        int segM = seg / A + seg / B - seg / lcm;

        int left = N % segM;
        long long base = (long long)seg * (long long)(N / segM);
        if(left == 0)
            return (int)(base % MOD);

        pair<long long, long long> d = make_pair((long long)A, (long long)B);
        for(int i = 0 ; i < left - 1; i ++)
            if(d.first <= d.second)
                d.first += (long long)A;
            else
                d.second += (long long)B;
        return (int)((base + min(d.first, d.second)) % MOD);
    }

private:
    int gcd(int A, int B){
        if(A > B)
            swap(A, B);
        if(B % A == 0)
            return A;
        return gcd(B % A, A);
    }
};


int main() {

    cout << Solution().nthMagicalNumber(1, 2, 3) << endl; // 2
    cout << Solution().nthMagicalNumber(4, 2, 3) << endl; // 6
    cout << Solution().nthMagicalNumber(5, 2, 4) << endl; // 10
    cout << Solution().nthMagicalNumber(3, 6, 4) << endl; // 8
    cout << Solution().nthMagicalNumber(2, 7, 3) << endl; // 6
    cout << Solution().nthMagicalNumber(3, 8, 3) << endl; // 8

    return 0;
}