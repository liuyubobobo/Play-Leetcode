/// Source : https://leetcode.com/problems/generate-parentheses/description/
/// Author : liuyubobobo
/// Time   : 2018-09-23

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>

using namespace std;


/// Recursively call generateParenthesis for smaller n
/// Time Complexity: O(2^n)
/// Space Complexity: O(2^n)
class Solution {

public:
    vector<string> generateParenthesis(int n) {

        if(n == 0)
            return {};

        vector<string> res;
        for(int i = 0; i <= n - 1; i ++){
            vector<string> left = generateParenthesis(i);
            if(left.size() == 0) left.push_back("");
            vector<string> right = generateParenthesis(n - i - 1);
            if(right.size() == 0) right.push_back("");
            for(const string& l: left)
                for(const string& r: right)
                    res.push_back("(" + l + ")" + r);
        }
        return res;
    }
};


void print_vec(const vector<string>& vec){
    for(const string& s: vec)
        cout << s << " ";
    cout << endl;
}

int main() {

    print_vec(Solution().generateParenthesis(1));
    print_vec(Solution().generateParenthesis(2));
    print_vec(Solution().generateParenthesis(3));

    return 0;
}