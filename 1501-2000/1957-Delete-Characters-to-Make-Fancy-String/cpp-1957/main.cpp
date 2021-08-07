/// Source : https://leetcode.com/problems/delete-characters-to-make-fancy-string/
/// Author : liuyubobobo
/// Time   : 2021-08-07

#include <iostream>

using namespace std;


/// String Split
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string makeFancyString(string s) {

        string res = "";
        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] != s[start]){
                int len = i - start;
                len = min(len, 2);
                res += string(len, s[start]);

                start = i;
                i = start;
            }
        return res;
    }
};


int main() {

    return 0;
}
