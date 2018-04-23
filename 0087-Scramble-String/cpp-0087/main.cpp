/// Source : https://leetcode.com/problems/scramble-string/description/
/// Author : liuyubobobo
/// Time   : 2018-04-23

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/// Recursive
/// Time Complexity: O(n^n)
/// Space Complexity: O(n^2)
class Solution {
public:
    bool isScramble(string s1, string s2) {

        if(s1.size() != s2.size())
            return false;

        if(s1 == s2)
            return true;

        unordered_map<char, int> freq;
        for(char c: s1)
            freq[c] += 1;
        for(char c: s2)
            if(freq.find(c) == freq.end())
                return false;
            else{
                freq[c] -= 1;
                if(freq[c] == 0)
                    freq.erase(c);
            }


        for(int i = 1 ; i <= s1.size() - 1 ; i ++){
            if(isScramble(s1.substr(0, i), s2.substr(0, i))
               && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0, i), s2.substr(s2.size() - i))
               && isScramble(s1.substr(i), s2.substr(0, s2.size() - i)))
                return true;
        }

        return false;
    }
};


void print_bool(bool res){
    cout << (res ? "true" : "false") << endl;
}

int main() {

    print_bool(Solution().isScramble("great", "rgeat"));
    print_bool(Solution().isScramble("abcde", "caebd"));
    print_bool(Solution().isScramble("abcdefghijklmn", "efghijklmncadb"));

    return 0;
}