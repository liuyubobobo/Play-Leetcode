/// Source : https://leetcode.com/problems/powx-n/
/// Author : liuyubobobo
/// Time   : 2018-12-20

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Classic Divide and Conquer to get power
/// Only deal with positive n
///
/// Time Complexity: O(logn)
/// Space Complexity: O(logn)
class Solution {
public:
    double myPow(double x, int n) {

        if(n == 0) return 1.0;

        double res = myPositivePow(x, abs((long long)n));
        if(n < 0) res = 1.0 / res;
        return res;
    }

private:
    double myPositivePow(double x, long long n){

        assert(n >= 0);
        if(!n) return 1.0;

        double t = myPositivePow(x, n / 2);
        double res = t * t;
        if(n % 2) res *= x;
        return res;
    }
};


int main() {

    cout << Solution().myPow(2.0, -2) << endl;
    // 0.25

    cout << Solution().myPow(-2.0, 2) << endl;
    // 4.0

    cout << Solution().myPow(34.00515, -3) << endl;
    // 3e-05

    cout << Solution().myPow(1.0, -2147483648) << endl;
    // 3e-05

    return 0;
}