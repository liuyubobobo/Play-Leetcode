/// Source : https://leetcode.com/problems/remove-invalid-parentheses/description/
/// Author : liuyubobobo
/// Time   : 2018-11-02

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Brute Force
/// Time Complexity: O(2^n)
/// Space Complexity: O(n)
class Solution {

private:
    int n;
    int maxlen;

public:
    vector<string> removeInvalidParentheses(string s) {

        n = s.size();
        maxlen = 0;

        unordered_set<string> res;
        dfs(s, 0, 0, "", res);
        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(const string& s, int index, int left, const string& cur,
             unordered_set<string>& res){

        if(index == n){
            if(left == 0){
                if(cur.size() > maxlen){
                    res.clear();
                    maxlen = cur.size();
                }

                if(cur.size() == maxlen)
                    res.insert(cur);
            }
            return;
        }

        if(s[index] != '(' && s[index] != ')')
            dfs(s, index + 1, left, cur + s[index], res);
        else if(s[index] == '('){
            dfs(s, index + 1, left + 1, cur + s[index], res);
            if(cur.size() + n - (index + 1) >= maxlen)
                dfs(s, index + 1, left, cur, res);
        }
        else{
            if(left > 0)
                dfs(s, index + 1, left - 1, cur + s[index], res);
            if(cur.size() + n - (index + 1) >= maxlen)
                dfs(s, index + 1, left, cur, res);
        }
    }
};


void print_vec(const vector<string>& vec){

    cout << vec.size() << " : ";
    for(const string& e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    string s1 = "()())()";
    print_vec(Solution().removeInvalidParentheses(s1));
    // 6
    // (())() ()()()

    string s2 = "(a)())()";
    print_vec(Solution().removeInvalidParentheses(s2));
    // 7
    // (a())() (a)()()

    string s3 = ")(";
    print_vec(Solution().removeInvalidParentheses(s3));
    // 0

    string s4 = "n";
    print_vec(Solution().removeInvalidParentheses(s4));
    // 1
    // n

    string s5 = "x(";
    print_vec(Solution().removeInvalidParentheses(s5));
    // 1
    // x

    string s6 = "((";
    print_vec(Solution().removeInvalidParentheses(s6));
    // 0


    return 0;
}