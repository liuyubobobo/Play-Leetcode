/// Source : https://leetcode.com/problems/valid-number/
/// Author : liuyubobobo
/// Time   : 2021-05-15

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool isNumber(string s) {

        if(s.size() == 0) return false;

        if(isInteger(s))
            return true;
        return isEDecimal(s);
    }

private:
    bool isEDecimal(const string& s){

        int epos = s.find('e');
        if(epos == string::npos) epos = s.find('E');
        if(epos != string::npos){
            string a = s.substr(0, epos), b = s.substr(epos + 1);
            return isDecimal(a) && isInteger(b);
        }
        return isDecimal(s);
    }

    bool isDecimal(const string& s){

        if(s.size() == 0) return false;

        if(s[0] == '+' || s[0] == '-')
            return isNonSignedDecimal(s.substr(1));
        return isNonSignedDecimal(s);
    }

    bool isNonSignedDecimal(const string& s){

        int dotpos = s.find('.');
        if(dotpos == string::npos) return isInteger(s);

        string a = s.substr(0, dotpos), b = s.substr(dotpos + 1);
        if(a.size() == 0) return isNonSignedInteger(b);
        else if(b.size() == 0) return isInteger(a);
        return isInteger(a) && isNonSignedInteger(b);
    }

    bool isInteger(const string& s){

        if(s.size() == 0) return false;
        if(s[0] == '+' || s[0] == '-')
            return isNonSignedInteger(s.substr(1));
        return isNonSignedInteger(s);
    }

    bool isNonSignedInteger(const string& s){

        if(s.size() == 0) return false;
        for(char c: s)
            if(!isdigit(c)) return false;
        return true;
    }
};


int main() {

    cout << Solution().isNumber(".1") << endl;
    // 1

    cout << Solution().isNumber("005047e+6") << endl;
    // 1

    cout << Solution().isNumber(".-4") << endl;
    // 0

    return 0;
}
