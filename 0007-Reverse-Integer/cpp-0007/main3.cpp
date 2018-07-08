/// Source : https://leetcode.com/problems/reverse-integer/description/
/// Author : liuyubobobo
/// Time   : 2018-07-08

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Poping digit one by one and check before overflow
/// Time Complexity: O(logx)
/// Space Complexity: O(1)
class Solution {
public:
    int reverse(int x) {

        if(x == 0)
            return x;

        if(x == INT_MIN)
            return 0;

        int sign = x > 0 ? 1 : -1;

        x = abs(x);
        int reverseNum = 0;
        while(x){

            if(reverseNum > INT_MAX / 10 || (reverseNum == INT_MAX / 10 && x % 10 > 7))
                return 0;

            reverseNum = reverseNum * 10 + x % 10;
            x /= 10;
        }

        return sign * reverseNum;
    }
};


int main() {

//    cout << INT_MAX << endl; // 2147483647
//    cout << INT_MIN << endl; // -2147483648

    cout << Solution().reverse(123) << endl;         // 321
    cout << Solution().reverse(-123) << endl;        // -321
    cout << Solution().reverse(12) << endl;          // 21
    cout << Solution().reverse(INT_MAX) << endl;     // 0
    cout << Solution().reverse(INT_MIN) << endl;     // 0
    cout << Solution().reverse(-2147483412) << endl; // -2143847412

    return 0;
}