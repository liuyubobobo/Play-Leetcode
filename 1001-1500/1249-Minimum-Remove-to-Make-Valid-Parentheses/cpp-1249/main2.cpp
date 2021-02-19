/// Source : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
/// Author : liuyubobobo
/// Time   : 2021-02-19

#include <iostream>
#include <vector>

using namespace std;


/// Stack - process on s directly
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {

        vector<bool> ok(s.size(), false);
        vector<int> stack;

        for(int i = 0; i < s.size(); i ++)
            if(isalpha(s[i])) ok[i] = true;
            else if(s[i] == '(') stack.push_back(i);
            else if(!stack.empty()){
                ok[i] = ok[stack.back()] = true;
                stack.pop_back();
            }

        string res = "";
        for(int i = 0; i < s.size(); i ++)
            if(ok[i]) res += s[i];
        return res;
    }
};


int main() {

    cout << Solution().minRemoveToMakeValid("lee(t(c)o)de)") << endl;
    // "lee(t(c)o)de"

    cout << Solution().minRemoveToMakeValid("a)b(c)d") << endl;
    // "ab(c)d"

    cout << Solution().minRemoveToMakeValid("))((") << endl;
    // ""

    cout << Solution().minRemoveToMakeValid("(a(b(c)d)") << endl;
    // "a(b(c)d)"

    cout << Solution().minRemoveToMakeValid("())()(((") << endl;
    // "()()"

    cout << Solution().minRemoveToMakeValid(")i()()((fm(((()") << endl;
    // "i()()fm()"

    cout << Solution().minRemoveToMakeValid(")((((()v))(()((s(())") << endl;
    // "((()v))()((s))"

    return 0;
}
