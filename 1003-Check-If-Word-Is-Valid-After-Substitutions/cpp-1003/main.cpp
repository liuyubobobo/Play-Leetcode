/// Source : https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
/// Author : liuyubobobo
/// Time   : 2019-03-02

#include <iostream>

using namespace std;


/// Ad-Hoc
/// Recursive
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    bool isValid(const string& s) {

        if(s.size() % 3) return false;
        if(s.size() == 0) return true;

        for(int i = 2; i < s.size(); i ++)
            if(s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c')
                return isValid(s.substr(0, i - 2) + s.substr(i + 1));
        return false;
    }
};


int main() {

    return 0;
}