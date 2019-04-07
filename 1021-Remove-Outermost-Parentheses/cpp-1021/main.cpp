/// Source : https://leetcode.com/problems/remove-outermost-parentheses/
/// Author : liuyubobobo
/// Time   : 2019-04-06

#include <iostream>
#include <stack>

using namespace std;


/// Using Stack
/// Time Complexity: O(|s|)
/// Space Complexity: O(1)
class Solution {
public:
    string removeOuterParentheses(string S) {

        string res = "";
        int stack = 1, start = 0;

        for(int i = 1; i < S.size(); i ++){

            if(S[i] == '(') stack ++;
            else stack --;

            if(stack == 0){
                res += S.substr(start + 1, i - start + 1 - 2);
                start = i + 1;
            }
        }
        return res;
    }
};


int main() {

    cout << Solution().removeOuterParentheses("(()())(())") << endl;

    return 0;
}