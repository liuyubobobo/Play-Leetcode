/// Source : https://leetcode.com/problems/powx-n/
/// Author : liuyubobobo
/// Time   : 2018-12-20

#include <iostream>
#include <vector>

using namespace std;


/// Classic Divide and Conquer to get power
/// Deal with both positive and negative n correctly
///
/// Time Complexity: O(logn)
/// Space Complexity: O(logn)
class Solution {
public:
    double myPow(double x, int n) {

        if(n == 0) return 1.0;

        double t = myPow(x, n / 2);
        if(n % 2 == 0)
            return t * t;
        else if( n > 0)
            return t * t * x;
        return t * t / x;
    }
};


int main() {

    cout << Solution().myPow(2.0, -2) << endl;
    // 0.25

    cout << Solution().myPow(-2.0, 2) << endl;
    // 4.0

    cout << Solution().myPow(34.00515, -3) << endl;
    // 3e-05

    return 0;
}