/// Source : https://leetcode.com/problems/reverse-words-in-a-string/description/
/// Author : liuyubobobo
/// Time   : 2018-08-10
/// Updated: 2021-07-02

#include <iostream>
#include <vector>

using namespace std;


/// Split and Reverse
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    string reverseWords(string &s) {

        vector<string> vec = split(s);
        if(vec.size() == 0){
            s = "";
            return s;
        }

        reverse(vec.begin(), vec.end());
        s = vec[0];
        for(int i = 1; i < vec.size() ; i ++)
            s += " " + vec[i];

        return s;
    }

private:
    vector<string> split(const string& s){

        vector<string> res;

        int start = nextNonSpace(s, 0);
        for(int i = start + 1; i <= s.size() ;)
            if(i == s.size() || s[i] == ' ') {
                res.push_back(s.substr(start, i - start));
                start = nextNonSpace(s, i);
                i = start + 1;
            }
            else
                i ++;

        return res;
    }

    int nextNonSpace(const string& s, int start){
        int i = start;
        for(; i < s.size() ; i ++)
            if(s[i] != ' ')
                return i;
        return i;
    }
};


int main() {

    string s1 = "the sky is blue";
    cout << Solution().reverseWords(s1) << endl;

    string s2 = "";
    cout << Solution().reverseWords(s2) << endl;

    return 0;
}