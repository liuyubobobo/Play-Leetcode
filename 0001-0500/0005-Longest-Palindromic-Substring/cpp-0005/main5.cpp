/// Source : https://leetcode.com/problems/longest-palindromic-substring/
/// Author : liuyubobobo
/// Time   : 2019-01-11

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Expand from center
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    string longestPalindrome(string s) {

        if(s == "") return s;

        int best = 0, n = s.size();
        string res = "";
        for(int center = 0; center < n; center ++){
            int len = 1, x;
            for(x = 1; x <= min(center, n - (center + 1)) && s[center - x] == s[center + x]; x ++)
                len += 2;
            if(len > best)
                best = len, res = s.substr(center - x + 1, len);
        }

        for(int center = 0; center + 1 < n; center ++)
            if(s[center] == s[center + 1]){
                int len = 2, x;
                for(x = 1; x <= min(center, n - (center + 2)) && s[center - x] == s[center + 1 + x]; x ++)
                    len += 2;
                if(len > best)
                    best = len, res = s.substr(center - x + 1, len);
            }
        return res;
    }
};


int main() {

    return 0;
}