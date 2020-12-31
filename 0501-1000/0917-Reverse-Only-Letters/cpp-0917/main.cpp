/// Source : https://leetcode.com/problems/reverse-only-letters/description/
/// Author : liuyubobobo
/// Time   : 2018-10-06

#include <iostream>

using namespace std;


/// Two Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string reverseOnlyLetters(string S) {

        int i = nextLetter(S, 0), j = prevLetter(S, S.size() - 1);
        while(i < j){
            swap(S[i], S[j]);
            i = nextLetter(S, i + 1);
            j = prevLetter(S, j - 1);
        }
        return S;
    }

private:
    int nextLetter(const string& s, int start){
        for(int i = start; i < s.size(); i ++)
            if(isalpha(s[i]))
                return i;
        return s.size();
    }

    int prevLetter(const string& s, int start){
        for(int i = start; i >= 0; i --)
            if(isalpha(s[i]))
                return i;
        return -1;
    }
};


int main() {

    return 0;
}