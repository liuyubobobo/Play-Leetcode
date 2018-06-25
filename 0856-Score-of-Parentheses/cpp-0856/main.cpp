/// Source : https://leetcode.com/problems/score-of-parentheses/description/
/// Author : liuyubobobo
/// Time   : 2018-06-23

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

/// Recursive
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int scoreOfParentheses(string S) {

        int res = 0;

        int left = 0;
        int start = 0;
        for(int i = 0 ; i < S.size() ; i ++){
            if(S[i] == '(')
                left ++;
            else{
                left --;
                if(left == 0){
                    res += score(S, start, i);
                    start = i + 1;
                }
            }
        }
        return res;
    }

private:
    int score(const string& s, int l, int r){

        if(l + 1 == r){
            assert(s[l] == '(' && s[r] == ')');
            return 1;
        }

        return 2 * scoreOfParentheses(s.substr(l + 1, r - l + 1 - 2));
    }
};


int main() {

    cout << Solution().scoreOfParentheses("()") << endl;
    cout << Solution().scoreOfParentheses("(())") << endl;
    cout << Solution().scoreOfParentheses("()()") << endl;
    cout << Solution().scoreOfParentheses("(()(()))") << endl;

    return 0;
}