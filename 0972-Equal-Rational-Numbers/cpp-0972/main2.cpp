/// Source : https://leetcode.com/problems/equal-rational-numbers/
/// Author : liuyubobobo
/// Time   : 2018-01-06

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;


/// Implement a Fraction class
/// Using geometric sum to deal with the repeat part :-)
///
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Fraction{

private:
    const double e = 1e-8;
    double x = 0.0;

public:
    Fraction(const string& s){
        int dot = s.find('.');
        if(dot == string::npos)
            x = atoi(s.c_str());
        else{
            x = atoi(s.substr(0, dot).c_str());

            string t = s.substr(dot + 1);
            int l = t.find('(');
            if(l == string::npos)
                x += (double)atoi(t.c_str()) * pow(0.1, t.size());
            else{
                assert(t.back() == ')');
                string decimal_part = t.substr(0, l);
                x += (double)atoi(decimal_part.c_str()) * pow(0.1, decimal_part.size());

                string repeat_part = t.substr(l + 1, t.size() - decimal_part.size() - 2);
                double r = pow(0.1, repeat_part.size());
                x += (double)atoi(repeat_part.c_str()) * pow(0.1, decimal_part.size()) * r / (1 - r);
            }
        }
    }

    bool rational_equal(Fraction& another){
        return abs(x - another.x) < e;
    }
};

class Solution {

public:
    bool isRationalEqual(string S, string T) {

        Fraction s = Fraction(S), t = Fraction(T);
        return s.rational_equal(t);
    }
};


int main() {

    string S1 = "0.(52)", T1 = "0.5(25)";
    cout << Solution().isRationalEqual(S1, T1) << endl;
    // true

    string S2 = "0.1666(6)", T2 = "0.166(66)";
    cout << Solution().isRationalEqual(S2, T2) << endl;
    // true

    string S3 = "0.9(9)", T3 = "1.";
    cout << Solution().isRationalEqual(S3, T3) << endl;
    // true

    return 0;
}