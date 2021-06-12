/// Source : https://leetcode.com/problems/ternary-expression-parser/
/// Author : liuyubobobo
/// Time   : 2021-06-12

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string parseTernary(string expression) {

        int n = expression.size();
        vector<int> match(n, -1);
        stack<int> stack;
        for(int i = 0; i < n; i ++)
            if(expression[i] == '?')
                stack.push(i);
            else if(expression[i] == ':'){
                assert(!stack.empty());
                match[stack.top()] = i;
                match[i] = stack.top();
                stack.pop();
            }

        return eval(expression, 0, n - 1, match);
    }

private:
    string eval(const string& exp, int l, int r, const vector<int>& match){

        if(l == r){
//            assert(isdigit(exp[l]));
            return exp.substr(l, 1);
        }

        assert(exp[l] == 'T' || exp[l] == 'F');
        assert(exp[l + 1] == '?');
        if(exp[l] == 'T') return eval(exp, l + 2, match[l + 1] - 1, match);
        return eval(exp, match[l + 1] + 1, r, match);
    }
};


int main() {

    cout << Solution().parseTernary("T?2:3") << endl;
    // 2

    cout << Solution().parseTernary("F?1:T?4:5") << endl;
    // 4

    cout << Solution().parseTernary("T?T?F:5:3") << endl;
    // F

    return 0;
}
