/// Source : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
/// Author : liuyubobobo
/// Time   : 2018-10-14

#include <iostream>
#include <stack>

using namespace std;


/// Using balance to record the stack top '(' size
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minAddToMakeValid(string S) {

        int res = 0, bal = 0;
        for(char c: S)
            if(c == '(')
                res ++, bal ++;
            else{
                if(bal)
                    res --, bal --;
                else
                    res ++, bal = 0;
            }
        return res;
    }
};


int main() {

    cout << Solution().minAddToMakeValid("()))((") << endl;
    // 4

    return 0;
}