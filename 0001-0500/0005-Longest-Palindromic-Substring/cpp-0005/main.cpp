/// Source : https://leetcode.com/problems/longest-palindromic-substring/
/// Author : liuyubobobo
/// Time   : 2019-01-11

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^3)
/// Space Complexity: O(1)
class Solution {
public:
    string longestPalindrome(string s) {

        if(s == "") return s;

        int n = s.size();
        string res = s.substr(0, 1);
        for(int i = 0; i < n; i ++)
            for(int j = i + res.size(); j < n; j ++)
                if(ok(s, i, j) && j - i + 1 > res.size())
                    res = s.substr(i, j - i + 1);
        return res;
    }

private:
    bool ok(const string& s, int a, int b){
        for(; a < b && s[a] == s[b]; a ++, b --);
        return a >= b;
    }
};


int main() {

    return 0;
}