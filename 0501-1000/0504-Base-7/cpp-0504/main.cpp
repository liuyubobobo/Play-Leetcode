/// Source : https://leetcode.com/problems/base-7/
/// Author : liuyubobobo
/// Time   : 2022-03-06

#include <iostream>
#include <algorithm>

using namespace std;


/// Simulation
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    string convertToBase7(int num) {

        bool pos = true;
        if(num < 0) num = -num, pos = false;

        string res = "";
        while(num){
            res += (char)('0' + num % 7);
            num /= 7;
        }
        reverse(res.begin(), res.end());
        if(res.empty()) res = "0";

        return (pos ? "" : "-") + res;
    }
};


int main() {

    return 0;
}
