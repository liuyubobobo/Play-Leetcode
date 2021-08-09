/// Source : https://leetcode.com/problems/add-strings/
/// Author : liuyubobobo
/// Time   : 2021-08-09

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string addStrings(string num1, string num2) {

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        if(num1.size() < num2.size()) swap(num1, num2);
        while(num2.size() <= num1.size()) num2 += "0";

        string res = "";
        int carry = 0;
        for(int i = 0; i < num1.size(); i ++){
            int x = (num1[i] - '0') + (num2[i] - '0') + carry;
            res += string(1, '0' + x % 10);
            carry = x / 10;
        }
        if(carry) res += "1";

        reverse(res.begin(), res.end());
        return res == "" ? "0" : res;
    }
};

int main() {

    cout << Solution().addStrings("11", "123") << endl;
    // 134

    return 0;
}
