/// Source : https://leetcode.com/problems/score-of-parentheses/description/
/// Author : liuyubobobo
/// Time   : 2018-06-25

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

/// Recursive Optimized
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int scoreOfParentheses(string S) {

        return score(S, 0, S.size() - 1);
    }

private:
    int score(const string& s, int l, int r){

        int res = 0;

        int balance = 0;
        int start = l;
        for(int i = l ; i <= r ; i ++){
            if(s[i] == '(')
                balance ++;
            else{
                balance --;

                if(balance == 0){
                    if(l + 1 == i)
                        res += 1;
                    else
                        res += 2 * score(s, l + 1, i - 1);
                    l = i + 1;
                }
            }
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