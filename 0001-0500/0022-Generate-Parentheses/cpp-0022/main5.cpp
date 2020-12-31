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

public:
    vector<string> generateParenthesis(int n){

        if(n == 0)
            return {};

        vector<vector<string>> res(n + 1);
        res[0].push_back("");
        for(int i = 1; i <= n; i ++)
            for(int j = 0; j <= i - 1; j ++)
                for(const string& l: res[j])
                    for(const string& r: res[i - j - 1])
                        res[i].push_back("(" + l + ")" + r);
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