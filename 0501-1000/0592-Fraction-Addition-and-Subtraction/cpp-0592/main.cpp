/// Source : https://leetcode.com/problems/fraction-addition-and-subtraction/
/// Author : liuyubobobo
/// Time   : 2022-07-26

#include <iostream>

using namespace std;


/// String Parse
/// Time Complexity: O(|exp|)
/// Space Complexity: O(1)
class Solution {
public:
    string fractionAddition(string expression) {

        if(expression[0] != '-') expression = "+" + expression;

        long long upper = 0, lower = 1;
        for(int start = 0, i = 1; i <= expression.size(); i ++)
            if(i == expression.size() || (expression[i] == '+' || expression[i] == '-')){

                string f = expression.substr(start, i - start);
                char op = f[0];

                f = f.substr(1);
                int div = f.find('/');

                long long a = atoll(f.substr(0, div).c_str());
                long long b = atoll(f.substr(div + 1).c_str());

                if(op == '+'){
                    long long new_a = upper * b + a * lower;
                    long long new_b = b * lower;
                    upper = new_a, lower = new_b;
                }
                else{
                    long long new_a = upper * b - a * lower;
                    long long new_b = b * lower;
                    upper = new_a, lower = new_b;
                }

                long long g = gcd(abs(upper), abs(lower));
                upper /= g, lower /= g;

                start = i;
            }

        return to_string(upper) + "/" + to_string(lower);
    }

private:
    int gcd(long long a, long long b){

        if(a > b) swap(a, b);

        if (a == 0) return b;
        return gcd(b % a, a);
    }
};


int main() {

    return 0;
}
