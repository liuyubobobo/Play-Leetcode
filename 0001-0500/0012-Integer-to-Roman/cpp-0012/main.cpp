/// Source : https://leetcode.com/problems/integer-to-roman/description/
/// Author : liuyubobobo
/// Time   : 2018-09-16

#include <iostream>
#include <cmath>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    string intToRoman(int num) {

        string res = "";
        string one[] = {"I", "X", "C", "M", ""}, five[] = {"V", "L", "D", ""};
        for(int k = 3; k >= 0; k --){
            int b = (int)pow(10, k);
            if(num >= b){
                int x = num / b;
                res += rome(x, one[k], five[k], one[k + 1]);
                num %= b;
            }
        }
        return res;
    }

private:
    string rome(int x, string one, string five, string ten){
        if(x <= 3)
            return string(x, one[0]);
        else if(x == 4)
            return one + five;
        else if(x <= 8)
            return five + string(x - 5, one[0]);
        // x == 9
        return one + ten;
    }
};


int main() {

    return 0;
}