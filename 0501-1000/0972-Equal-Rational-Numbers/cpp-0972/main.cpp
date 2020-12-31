/// Source : https://leetcode.com/problems/equal-rational-numbers/
/// Author : liuyubobobo
/// Time   : 2018-01-05

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;


/// Implement a Fraction class
/// For rational equal, try to compare the two fraction string
/// or adding 0.000...0001 to the smaller fraction and compare again
///
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Fraction{

private:
    const int n = 100;
    string integer_part, decimal_part;

public:
    Fraction(const string& s){
        int dot = s.find('.');
        if(dot == string::npos){
            integer_part = s;
            decimal_part = string(n, '0');
        }
        else{
            integer_part = s.substr(0, dot);
            string t = s.substr(dot + 1);
            int l = t.find('(');
            if(l == string::npos)
                decimal_part = t + string(n - t.size(), '0');
            else{
                assert(t.back() == ')');
                decimal_part = t.substr(0, l);
                string repeat_part = t.substr(l + 1, t.size() - decimal_part.size() - 2);
                while(decimal_part.size() <= n)
                    decimal_part += repeat_part;
                decimal_part = decimal_part.substr(0, n);
            }
        }
    }

    bool rational_equal(Fraction& another){

        if(*this == another)
            return true;

        if(*this < another){
            Fraction x = this->add_a_bit();
            return x == another;
        }

        Fraction x = another.add_a_bit();
        return *this == x;
    }

    Fraction add_a_bit(){

        int carry = 0;
        string new_decimal_part = add_one(decimal_part, carry);
        string new_integer_part = integer_part;
        if(carry){
            carry = 0;
            new_integer_part = add_one(integer_part, carry);
            if(carry) new_integer_part = "1" + new_integer_part;
        }
        return Fraction(new_integer_part + "." + new_decimal_part);
    }

    bool operator==(const Fraction& another){
        return this->integer_part == another.integer_part &&
               this->decimal_part == another.decimal_part;
    }

    bool operator<(const Fraction& another){
        return this->integer_part < another.integer_part ||
               (this->integer_part == another.integer_part &&
                this->decimal_part < another.decimal_part);
    }

private:
    string add_one(const string& s, int& ret_carry){

        string res = s;
        assert(res.size() > 0);

        res[res.size() - 1] += 1;
        int carry = 0;
        for(int i = (int)res.size() - 1; i >= 0; i --){
            int num = res[i] - '0' + carry;
            res[i] = '0' + num % 10;
            carry = num / 10;
        }
        ret_carry = carry;
        return res;
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

    string S2 = "0.1666(6)", T2 = "0.166(66)";
    cout << Solution().isRationalEqual(S2, T2) << endl;

    string S3 = "0.9(9)", T3 = "1.";
    cout << Solution().isRationalEqual(S3, T3) << endl;

    return 0;
}