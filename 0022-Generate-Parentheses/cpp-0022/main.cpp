/// Source : https://leetcode.com/problems/generate-parentheses/description/
/// Author : liuyubobobo
/// Time   : 2018-09-23

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


/// Generate all permutation and check validation
/// Time Complexity: O(n*2^n)
/// Space Complexity: O(n)
class Solution {

public:
    vector<string> generateParenthesis(int n) {

        string s = string(n, '(') + string(n, ')');
        vector<string> res;
        do{
            if(valid(s))
                res.push_back(s);
        }while(next_permutation(s.begin(), s.end()));
        return res;
    }

private:
    bool valid(const string& s){

        stack<char> stack;
        for(char c: s)
            if(c == '(')
                stack.push(c);
            else if(stack.empty())
                return false;
            else
                stack.pop();
        return true;
    }
};


int main() {

    return 0;
}