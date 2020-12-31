/// Source : https://leetcode.com/problems/remove-palindromic-subsequences/
/// Author : liuyubobobo
/// Time   : 2020-02-21

#include <iostream>

using namespace std;


/// Mathematics
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int removePalindromeSub(string s) {

        if(s == "") return 0;
        return isPalindrome(s) ? 1 : 2;
    }

private:
    bool isPalindrome(const string& s){

        for(int i = 0, j = s.size() - 1; i < j; i ++, j --)
            if(s[i] != s[j]) return false;
        return true;
    }
};


int main() {

    return 0;
}
