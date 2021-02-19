/// Source : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
/// Author : liuyubobobo
/// Time   : 2021-02-19

#include <iostream>
#include <vector>

using namespace std;


/// Stack - get braces pattern first
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {

        string temp = "";
        for(char c: s)
            if(!isalpha(c)) temp += c;

        string pattern = get_pattern(temp);
//        cout << pattern << endl;

        string res = "";
        int p = 0;
        for(char c: s)
            if(isalpha(c))
                res += c;
            else if(p < pattern.size() && pattern[p] == c)
                res += c, p ++;
        return res;
    }

private:
    string get_pattern(const string& t){

        vector<bool> ok(t.size(), false);
        vector<int> stack;
        for(int i = 0; i < t.size(); i ++)
            if(t[i] == '(') stack.push_back(i);
            else if(!stack.empty()){
                ok[i] = ok[stack.back()] = true;
                stack.pop_back();
            }

        string res = "";
        for(int i = 0; i < t.size(); i ++)
            if(ok[i]) res += t[i];
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
