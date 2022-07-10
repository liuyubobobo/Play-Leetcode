/// Source : https://leetcode.com/problems/valid-palindrome-iv/
/// Author : liuyubobobo
/// Time   : 2022-07-10

#include <iostream>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool makePalindrome(string s) {

        int n = s.size(), res = 0;
        for(int i = 0, j = n - 1; i < j; i ++, j --)
            res += s[i] != s[j];

        return res <= 2;
    }
};


int main() {

    return 0;
}
