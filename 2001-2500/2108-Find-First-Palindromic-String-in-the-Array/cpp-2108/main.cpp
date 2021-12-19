/// Source : https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
/// Author : liuyubobobo
/// Time   : 2021-12-18

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * |s|)
/// Space Complexity: O(1)
class Solution {
public:
    string firstPalindrome(vector<string>& words) {

        for(const string& s: words)
            if(is_palindrome(s)) return s;
        return "";
    }

private:
    bool is_palindrome(const string& s){

        int n = s.size();
        for(int i = 0; i < n; i ++)
            if(s[i] != s[n - 1 - i]) return false;
        return true;
    }
};


int main() {

    return 0;
}
