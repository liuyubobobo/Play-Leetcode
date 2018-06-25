/// Source : https://leetcode.com/problems/score-of-parentheses/description/
/// Author : liuyubobobo
/// Time   : 2018-06-25

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

/// Calculating Cores
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int scoreOfParentheses(string S) {

        int balance = 0;
        int res = 0;
        for(int i = 0 ; i < S.size() ; i ++)
            if(S[i] == '(')
                balance ++;
            else{
                balance --;
                if(S[i - 1] == '(')
                    res += (1 << balance);
            }

        return res;
    }
};


int main() {

    cout << Solution().scoreOfParentheses("()") << endl; // 1
    cout << Solution().scoreOfParentheses("(())") << endl; // 2
    cout << Solution().scoreOfParentheses("()()") << endl; // 2
    cout << Solution().scoreOfParentheses("(()(()))") << endl; // 6

    return 0;
}