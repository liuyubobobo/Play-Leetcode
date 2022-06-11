/// Source : https://leetcode.com/problems/strong-password-checker-ii/
/// Author : liuyubobobo
/// Time   : 2022-06-11

#include <iostream>
#include <vector>
#include <string>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool strongPasswordCheckerII(string password) {

        if(password.size() < 8) return false;

        bool lower_ok = false;
        for(char c: password) if(islower(c)) lower_ok = true;
        if(!lower_ok) return false;

        bool upper_ok = false;
        for(char c: password) if(isupper(c)) upper_ok = true;
        if(!upper_ok) return false;

        bool digit_ok = false;
        for(char c: password) if(isdigit(c)) digit_ok = true;
        if(!digit_ok) return false;

        bool special_ok = false;
        string special = "!@#$%^&*()-+";
        for(char c: password) if(special.find(c) != string::npos) special_ok = true;
        if(!special_ok) return false;

        for(int i = 1; i < password.size(); i ++)
            if(password[i - 1] == password[i]) return false;
        return true;
    }
};


int main() {

    return 0;
}
