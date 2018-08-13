/// Source : https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
/// Author : liuyubobobo
/// Time   : 2018-08-12

#include <iostream>
#include <vector>

using namespace std;

/// split and reverse
/// Time Complexity: O(len(s))
/// Space Complexity: O(n)
class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;
        int start = 0;
        for(int i = start + 1; i <= s.size(); )
            if(i == s.size() || s[i] == ' '){
                words.push_back(s.substr(start, i - start));
                reverse(words.back().begin(), words.back().end());
                start = i + 1;
                i = start + 1;
            }
            else
                i ++;

        if(words.size() == 0)
            return "";

        string res = words[0];
        for(int i = 1;  i < words.size() ; i ++)
            res += " " + words[i];

        return res;
    }
};


int main() {

    return 0;
}