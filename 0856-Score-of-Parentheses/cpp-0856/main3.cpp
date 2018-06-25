/// Source : https://leetcode.com/problems/score-of-parentheses/description/
/// Author : liuyubobobo
/// Time   : 2018-06-25

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

/// Using a Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int scoreOfParentheses(string S) {

        stack<int> stack;
        stack.push(0);
        for(char c: S){
            if(c == '(')
                stack.push(0);
            else{
                int v = stack.top();
                stack.pop();
                int w = stack.top();
                stack.pop();

                stack.push(w + max(2 * v, 1));
            }
        }

        return stack.top();
    }
};


int main() {

    cout << Solution().scoreOfParentheses("()") << endl; // 1
    cout << Solution().scoreOfParentheses("(())") << endl; // 2
    cout << Solution().scoreOfParentheses("()()") << endl; // 2
    cout << Solution().scoreOfParentheses("(()(()))") << endl; // 6

    return 0;
}