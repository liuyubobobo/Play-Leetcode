/// Source : https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
/// Author : liuyubobobo
/// Time   : 2018-08-12

#include <iostream>

using namespace std;

/// Reverse in place
/// Time Complexity: O(len(s))
/// Space Complexity: O(1)
class Solution {
public:
    string reverseWords(string s) {

        int start = 0;
        for(int i = start + 1; i <= s.size(); )
            if(i == s.size() || s[i] == ' '){
                reverse(s, start, i - 1);
                start = i + 1;
                i = start + 1;
            }
            else
                i ++;
        return s;
    }

private:
    void reverse(string& s, int start, int end){
        for(int i = start, j = end; i < j; i ++, j --)
            swap(s[i], s[j]);
    }
};


int main() {

    return 0;
}