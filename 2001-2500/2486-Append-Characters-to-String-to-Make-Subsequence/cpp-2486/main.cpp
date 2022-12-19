/// Source : https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/
/// Author : liuyubobobo
/// Time   : 2022-12-18

#include <iostream>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int appendCharacters(string s, string t) {

        int j = 0;
        for(int i = 0; i < s.size(); i ++)
            if(j < t.size() && s[i] == t[j]) j ++;
        return t.size() - j;
    }
};


int main() {

    return 0;
}
