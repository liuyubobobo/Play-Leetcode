/// Source : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
/// Author : liuyubobobo
/// Time   : 2019-09-15

#include <iostream>
#include <stack>

using namespace std;


/// Recursion
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    string reverseParentheses(string s) {

        int start;
        for(int i = 0; i < s.size(); i ++)
            if(s[i] == '(') start = i;
            else if(s[i] == ')'){
                string t = s.substr(start + 1, i - (start + 1));
                reverse(t.begin(), t.end());
                return reverseParentheses(s.substr(0, start) + t + s.substr(i + 1));
            }
        return s;
    }
};


int main() {

    cout << Solution().reverseParentheses("(abcd)") << endl;
    // dcba

    cout << Solution().reverseParentheses("(u(love)i)") << endl;
    // iloveu

    cout << Solution().reverseParentheses("(ed(et(oc))el)") << endl;
    // leetcode

    cout << Solution().reverseParentheses("a(bcdefghijkl(mno)p)q") << endl;
    // apmnolkjihgfedcbq

    return 0;
}