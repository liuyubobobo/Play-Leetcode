/// Source : https://leetcode.com/problems/longest-palindromic-substring/
/// Author : liuyubobobo
/// Time   : 2019-07-25

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Manacher's Algorithm
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string longestPalindrome(string input) {

        string s = "#";
        for(char c: input)
            s += c, s += '#';

        int id = 0, maxright = 0;
        int rescenter = 0, reslen = 0;
        vector<int> r(s.size(), 0);
        for(int i = 1; i < s.size() - 1; i ++){
            r[i] = maxright > i ? min(r[2 * id - i], maxright - i) : 1;
            while(i - r[i] >= 0 && i + r[i] < s.size() && s[i + r[i]] == s[i - r[i]]) r[i] ++;
            r[i] --;

            if(i + r[i] > maxright) maxright = i + r[i], id = i;

            if(r[i] > reslen) reslen = r[i], rescenter = i;
        }

        return input.substr((rescenter - reslen) / 2, reslen);
    }
};


int main() {

    cout << Solution().longestPalindrome("babad") << endl;

    return 0;
}