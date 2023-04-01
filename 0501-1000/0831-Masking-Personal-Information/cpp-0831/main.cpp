/// Source : https://leetcode.com/problems/masking-personal-information/
/// Author : liuyubobobo
/// Time   : 2023-03-31

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(|s|)
/// Space Complexity: O(|s|)
class Solution {
public:
    string maskPII(string s) {

        if(s.find('@') != string::npos) return solve_email(s);
        return solve_phone(s);
    }

private:
    string solve_phone(string& s){

        string number;
        for(char c: s) if(isdigit(c)) number += c;

        int n = number.size();

        if(n == 10) return "***-***-" + number.substr(n - 4);
        return "+" + string(n - 10, '*') + "-***-***-" + number.substr(n - 4);
    }

    string solve_email(string& s){

        for(char& c: s) if(isupper(c)) c = tolower(c);

        int pos = s.find('@');
        string name = s.substr(0, pos), domain = s.substr(pos + 1);

        return string(1, name[0]) + "*****" + string(1, name.back()) + "@" + domain;
    }
};


int main() {

    return 0;
}
