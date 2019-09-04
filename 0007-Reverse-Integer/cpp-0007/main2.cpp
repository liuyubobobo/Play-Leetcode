/// Source : https://leetcode.com/problems/reverse-integer/description/
/// Author : liuyubobobo
/// Time   : 2018-07-08

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Using digit vector to solve the overflow problem
/// Time Complexity: O(logx)
/// Space Complexity: O(logx)
class Solution {
public:
    int reverse(int x) {

        if(x == 0)
            return x;

        if(x == INT_MIN)
            return 0;

        int sign = x > 0 ? 1 : -1;

        x = abs(x);
        vector<int> reverseDigits;
        while(x){
            reverseDigits.push_back(x % 10);
            x /= 10;
        }

        if(sign > 0 && overflow(reverseDigits, {2, 1, 4, 7, 4, 8, 3, 6, 4, 7}))
            return 0;
        else if(sign < 0 && overflow(reverseDigits, {2, 1, 4, 7, 4, 8, 3, 6, 4, 8}))
            return 0;

        return sign * getNumber(reverseDigits);
    }

private:
    int getNumber(const vector<int>& digits){
        int res = 0;
        for(int digit: digits)
            res = res * 10 + digit;
        return res;
    }

    bool overflow(const vector<int>& digits, const vector<int>& max){

        if(digits.size() < max.size())
            return false;

        assert(digits.size() == max.size());
        for(int i = 0 ; i < digits.size() ; i ++)
            if(digits[i] > max[i])
                return true;
            else if(digits[i] < max[i])
                return false;
        return false;
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