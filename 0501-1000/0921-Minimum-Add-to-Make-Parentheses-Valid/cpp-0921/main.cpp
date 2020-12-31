/// Source : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
/// Author : liuyubobobo
/// Time   : 2018-10-13

#include <iostream>
#include <stack>

using namespace std;


/// Using Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minAddToMakeValid(string S) {

        stack<char> s;
        for(char c: S)
            if(c == '(')
                s.push(c);
            else{
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else
                    s.push(c);
            }
        return s.size();
    }
};


int main() {

    cout << Solution().minAddToMakeValid("()))((") << endl;
    // 4

    return 0;
}