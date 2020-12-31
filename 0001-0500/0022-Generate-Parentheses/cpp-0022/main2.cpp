/// Source : https://leetcode.com/problems/generate-parentheses/description/
/// Author : liuyubobobo
/// Time   : 2018-09-23

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


/// Generate all valid permutation directly
/// Time Complexity: O(2^n)
/// Space Complexity: O(n)
class Solution {

public:
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        generate(n, n, "", res);
        return res;
    }

private:
    void generate(int left, int right, const string& cur, vector<string>& res){

        if(left == 0 && right == 0){
            res.push_back(cur);
            return;
        }

        if(left)
            generate(left - 1, right, cur + '(', res);

        if(right && left < right)
            generate(left, right - 1, cur + ')', res);
    }
};


int main() {

    return 0;
}