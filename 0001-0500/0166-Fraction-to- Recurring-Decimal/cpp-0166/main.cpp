/// Source : https://leetcode.com/problems/fraction-to-recurring-decimal/
/// Author : liuyubobobo
/// Time   : 2021-10-02

#include <iostream>
#include <map>

using namespace std;


/// Simulation
/// Time Complexity: O(denominator)
/// Space Complexity: O(denominator)
class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {

        if(numerator == 0) return "0";

        string res = "";
        if(sign(numerator) * sign(denominator) < 0)
            res += "-";

        numerator = abs(numerator);
        denominator = abs(denominator);

        res += to_string(numerator / denominator);
        numerator %= denominator;

        if(numerator == 0) return res;

        res += ".";

        map<long long, int> pos;
        while(numerator){
            numerator *= 10;
            if(pos.count(numerator)){
                int p = pos[numerator];
                string a = res.substr(0, p), b = res.substr(p);
                return a + "(" + b + ")";
            }

            pos[numerator] = res.size();
            res += ('0' + (numerator / denominator));
            numerator %= denominator;
        }
        return res;
    }

private:
    int sign(long long x){
        return x > 0 ? 1 : -1;
    }
};


int main() {

    cout << Solution().fractionToDecimal(1, 2) << endl;
    // 0.5

    cout << Solution().fractionToDecimal(2, 1) << endl;
    // 2

    cout << Solution().fractionToDecimal(2, 3) << endl;
    // 0.(6)

    cout << Solution().fractionToDecimal(4, 333) << endl;
    // 0.(012)

    cout << Solution().fractionToDecimal(1, 5) << endl;
    // 0.2

    return 0;
}
