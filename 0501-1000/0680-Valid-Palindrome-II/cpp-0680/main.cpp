/// Source : https://leetcode.com/problems/valid-palindrome-ii/
/// Author : liuyubobobo
/// Time   : 2022-04-01

#include <iostream>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool validPalindrome(string s) {

        int n = s.size();
        if(is_palindrome(s, 0, n - 1)) return true;

        int i = 0, j = n - 1;
        while(s[i] == s[j]) i ++, j --;
        return is_palindrome(s, i + 1, j) || is_palindrome(s, i, j - 1);
    }

private:
    bool is_palindrome(const string& s, int l, int r){
        for(int i = l, j = r; i < j; i ++, j --)
            if(s[i] != s[j]) return false;
        return true;
    }
};


int main() {

    cout << Solution().validPalindrome("abca") << '\n';

    return 0;
}
