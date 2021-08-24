/// Source : https://leetcode.com/problems/complex-number-multiplication/
/// Author : liuyubobobo
/// Time   : 2021-08-24

#include <iostream>
#include <complex>

using namespace std;


/// Brute Force
/// Time Complexity: O(|num1 + num2|)
/// Space Complexity: O(1)
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {

        complex<int> p1 = get_complex(num1);
        complex<int> p2 = get_complex(num2);

        complex<int> res = p1 * p2;
        return to_string(res.real()) + "+" + to_string(res.imag()) + "i";
    }

private:
    complex<int> get_complex(const string& num){

        int add = num.find('+');
        int real = atoi(num.substr(0, add).c_str());

        int img = atoi(num.substr(add + 1, num.size() - (add + 1) - 1).c_str());

        return complex<int>(real, img);
    }
};


int main() {

    return 0;
}
