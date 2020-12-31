/// Source : https://leetcode.com/problems/reverse-words-in-a-string/description/
/// Author : liuyubobobo
/// Time   : 2018-08-12

#include <iostream>
#include <vector>

using namespace std;


/// Reverse then reverse
/// really do all the things in place:)
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    void reverseWords(string &s) {

        int search_start = nextNonSpace(s, 0);
        if(search_start == s.size()){
            s = "";
            return;
        }

        int start = 0;
        for(int i = search_start + 1; i <= s.size() ; )
            if(i == s.size() || s[i] == ' '){

                for(int j = search_start; j < i ; j ++)
                    s[start++] = s[j];

                search_start = nextNonSpace(s, i);
                if(search_start == s.size()){
                    s = s.substr(0, start);
                    break;
                }
                else
                    s[start++] = ' ';

                i = search_start + 1;
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
    Solution().reverseWords(s1);
    cout << s1 << endl;

    string s2 = "";
    Solution().reverseWords(s2);
    cout << s2 << endl;

    string s3 = " 1 ";
    Solution().reverseWords(s3);
    cout << s3 << endl;

    string s4 = "   a   b ";
    Solution().reverseWords(s4);
    cout << s4 << endl;

    return 0;
}