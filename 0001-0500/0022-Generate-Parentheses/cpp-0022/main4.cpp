/// Source : https://leetcode.com/problems/generate-parentheses/description/
/// Author : liuyubobobo
/// Time   : 2018-09-23

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>

using namespace std;


/// Memory Search
/// Time Complexity: O(2^n)
/// Space Complexity: O(2^n)
class Solution {

private:
    vector<vector<string>> res;

public:
    vector<string> generateParenthesis(int n){

        res.clear();
        for(int i = 0; i <= n; i ++)
            res.push_back(vector<string>());
        return generate(n);
    }

private:
    vector<string> generate(int n) {

        if(n == 0)
            return {};

        if(res[n].size() != 0)
            return res[n];

        for(int i = 0; i <= n - 1; i ++){
            vector<string> left = generate(i);
            if(left.size() == 0) left.push_back("");
            vector<string> right = generate(n - i - 1);
            if(right.size() == 0) right.push_back("");
            for(const string& l: left)
                for(const string& r: right)
                    res[n].push_back("(" + l + ")" + r);
        }
        return res[n];
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