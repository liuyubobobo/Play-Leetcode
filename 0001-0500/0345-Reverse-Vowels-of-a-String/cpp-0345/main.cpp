/// Source : https://leetcode.com/problems/reverse-vowels-of-a-string/
/// Author : liuyubobobo
/// Time   : 2016-12-06
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Two Pointers
/// Time Complexity:  O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string reverseVowels(string s) {

        int i = nextVowelIndex(s, 0);
        int j = preVowelIndex(s, s.size() - 1);
        while(i < j){
            swap(s[i], s[j]);
            i = nextVowelIndex(s, i + 1);
            j = preVowelIndex(s, j - 1);
        }

        return s;
    }

private:
    int nextVowelIndex(const string &s, int index){
        for(int i = index ; i < s.size() ; i ++)
            if(isVowel(s[i]))
                return i;
        return s.size();
    }

    int preVowelIndex(const string &s, int index ){
        for(int i = index ; i >= 0 ; i --)
            if(isVowel(s[i]))
                return i;
        return -1;
    }

    bool isVowel(char c){
        char lowerc = tolower(c);
        return lowerc == 'a' || lowerc == 'e' || lowerc == 'i' || lowerc == 'o' || lowerc == 'u';
    }
};


int main() {

    cout << Solution().reverseVowels("hello") << endl;
    cout << Solution().reverseVowels("leetcode") << endl;

    return 0;
}