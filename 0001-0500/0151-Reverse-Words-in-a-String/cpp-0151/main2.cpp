/// Source : https://leetcode.com/problems/reverse-words-in-a-string/description/
/// Author : liuyubobobo
/// Time   : 2018-08-12
/// Updated: 2021-07-02

#include <iostream>
#include <vector>

using namespace std;


/// Reverse then reverse:)
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    string reverseWords(string &s) {

        int start = nextNonSpace(s, 0);
        s = s.substr(start);

        start = 0;
        for(int i = start + 1; i <= s.size() ; )
            if(i == s.size() || s[i] == ' '){
                start = nextNonSpace(s, i);
                if(start != s.size())
                    s = s.substr(0, i) + " " + s.substr(start);
                else{
                    s = s.substr(0, i);
                    break;
                }

                start = i + 1;
                i = start + 1;
            }
            else
                i ++;

        reverse(s, 0, s.size() - 1);
        start = 0;
        for(int i = start + 1; i <= s.size() ; )
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
    int nextNonSpace(const string& s, int start){
        int i = start;
        for(; i < s.size() ; i ++)
            if(s[i] != ' ')
                return i;
        return i;
    }

    void reverse(string& s, int start, int end){
        int i = start, j = end;
        while(i < j)
            swap(s[i++], s[j--]);
    }
};


int main() {

    string s1 = "the sky is blue";
    cout << Solution().reverseWords(s1) << endl;

    string s2 = "";
    cout << Solution().reverseWords(s2) << endl;

    string s3 = " 1 ";
    cout << Solution().reverseWords(s3) << endl;

    string s4 = "   a   b ";
    cout << Solution().reverseWords(s4) << endl;

    return 0;
}