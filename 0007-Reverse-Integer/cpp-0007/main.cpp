/// Source : https://leetcode.com/problems/reverse-integer/description/
/// Author : liuyubobobo
/// Time   : 2018-07-08

#include <iostream>

using namespace std;


/// Using long long to solve the overflow problem
/// Time Complexity: O(logx)
/// Space Complexity: O(logx)
class Solution {
public:
    int reverse(int x) {

        if(x == 0)
            return x;

        int sign = x > 0 ? 1 : -1;

        long long num = abs((long long)x);
        long long reverseNum = 0;
        while(num){
            reverseNum = reverseNum * 10 + num % 10;
            num /= 10;
        }

        reverseNum *= sign;
        if(reverseNum > INT_MAX || reverseNum < INT_MIN)
            return 0;
        return reverseNum;
    }
};


int main() {

    cout << Solution().reverse(123) << endl;
    cout << Solution().reverse(-123) << endl;
    cout << Solution().reverse(12) << endl;
    cout << Solution().reverse(INT_MAX) << endl;
    cout << Solution().reverse(INT_MIN) << endl;

    return 0;
}