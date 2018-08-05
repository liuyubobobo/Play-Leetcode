/// Source : https://leetcode.com/problems/nth-magical-number/description/
/// Author : liuyubobobo
/// Time   : 2018-08-03

#include <iostream>
#include <cassert>

using namespace std;


/// Binary Search Improved
/// Time Complexity: O(log(min(A, B) * N))
/// Space Complexity: O(1)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int nthMagicalNumber(int N, int A, int B) {

        int lcm = A * B / gcd(A, B);
        long long l = 2ll, r = (long long)min(A, B) * (long long)N;
        while(l < r){
            long long mid = l + (r - l) / 2;
            if(getRank(mid, A, B, lcm) >= (long long)N)
                r = mid;
            else
                l = mid + 1ll;
        }

        return (int)(l % MOD);
    }

private:
    long long getRank(long long num, int A, int B, int lcm){
        long long arank = num / (long long)A;
        long long brank = num / (long long)B;
        long long abrank = num / (long long)lcm;
        return arank + brank - abrank;
    }

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

    return 0;
}