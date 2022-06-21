/// Source : https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/
/// Author : liuyubobobo
/// Time   : 2022-06-18

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string greatestLetter(string s) {

        vector<bool> upper(26, false), lower(26, false);
        for(char c: s){
            if(isupper(c)) upper[c - 'A'] = true;
            else lower[c - 'a'] = true;
        }

        int res = -1;
        for(int i = 0; i < 26; i ++)
            if(upper[i] && lower[i]) res = i;
        return res == -1 ? "" : string(1, 'A' + res);
    }
};


int main() {

    return 0;
}
