/// Source : https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/description/
/// Author : liuyubobobo
/// Time   : 2023-06-19

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string smallestString(string s) {

        int start = 0;
        for(; start < s.size(); start ++) if(s[start] != 'a') break;
        if(start == s.size()) {
            s[s.size() - 1] = 'z';
            return s;
        }

        int end;
        for(end = start; end < s.size(); end ++) if(s[end] == 'a') break;

        for(int i = start; i < end; i ++) s[i] --;
        return s;
    }
};


int main() {

    return 0;
}
