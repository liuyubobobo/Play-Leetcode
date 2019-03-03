/// Source : https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
/// Author : liuyubobobo
/// Time   : 2019-03-03

#include <iostream>

using namespace std;


/// Ad-Hoc
/// Iterative
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    bool isValid(string s) {

        for(int i = s.find("abc"); i != string::npos; i = s.find("abc"))
            s.erase(i, 3);
        return s == "";
    }
};


int main() {

    return 0;
}