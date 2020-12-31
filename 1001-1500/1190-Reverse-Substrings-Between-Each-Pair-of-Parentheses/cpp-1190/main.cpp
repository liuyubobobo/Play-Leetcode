/// Source : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
/// Author : liuyubobobo
/// Time   : 2019-09-14

#include <iostream>
#include <stack>

using namespace std;


/// Using Stack
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    string reverseParentheses(string s) {

        string p = "", res = "";
        stack<int> stack;
        for(int i = 0; i < s.size(); i ++)
            if(s[i] == ')'){
//                cout << stack.top() << endl;
                string t = p.substr(stack.top() + 1);
                reverse(t.begin(), t.end());
                p = p.substr(0, p.size() - (t.size() + 1));
                p += t;
                stack.pop();
            }
            else{
                p += s[i];
                if(s[i] == '(') stack.push(p.size() - 1);
            }
        return p;
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