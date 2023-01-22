/// Source : https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/description/
/// Author : liuyubobobo
/// Time   : 2023-01-22

#include <iostream>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool makeStringsEqual(string s, string target) {

        int n = s.size() - 1;
        if(s == target) return true;

        bool s_has1 = false, s_all0 = true;
        for(char c: s) if(c == '1') s_has1 = true;
        for(char c: s) if(c == '1') s_all0 = false;

        bool t_has1 = false, t_all0 = true;
        for(char c: target) if(c == '1') t_has1 = true;
        for(char c: target) if(c == '1') t_all0 = false;

        if(s_has1 && t_all0) return false;
        if(t_has1 && s_all0) return false;
        return true;
    }
};


int main() {

    return 0;
}
