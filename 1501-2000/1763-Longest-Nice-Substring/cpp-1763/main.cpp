/// Source : https://leetcode.com/problems/longest-nice-substring/
/// Author : liuyubobobo
/// Time   : 2021-02-20

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^3)
/// Space Complexity: O(1)
class Solution {
public:
    string longestNiceSubstring(string s) {

        string res = "";
        for(int i = 0; i < s.size(); i ++)
            for(int len = 2; i + len <= s.size(); len ++)
                if(ok(s.substr(i, len)) && len > res.size())
                    res = s.substr(i, len);
        return res;
    }

private:
    bool ok(const string& s){

        vector<bool> lower(26, false), upper(26, false);
        for(char c: s)
            if(islower(c)) lower[c - 'a'] = true;
            else upper[c - 'A'] = true;

        for(int i = 0; i < 26; i ++)
            if(lower[i] ^ upper[i]) return false;
        return true;
    }
};


int main() {

    return 0;
}
