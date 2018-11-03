/// Source : https://leetcode.com/problems/remove-invalid-parentheses/description/
/// Author : liuyubobobo
/// Time   : 2018-11-02

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Calculate how many '(' and ')' are there
/// int the result maximum len expression first
/// Time Complexity: O(2^n)
/// Space Complexity: O(n)
class Solution {

private:
    int n, maxlen;

public:
    vector<string> removeInvalidParentheses(string s) {

        n = s.size();

        int total_left = 0, total_right = 0, l = 0, r = 0;
        for(char c: s){
            if(c == '(') total_left ++;
            else if(c == ')') total_right ++;

            if(c == '(') l ++;
            else if(c == ')'){
                if(l > 0) l --;
                else r ++;
            }
        }

        int rem_left = total_left - l, rem_right = total_right - r;
//        cout << "rem_left : " << rem_left << " ; rem_right : " << rem_right << endl;
        maxlen = s.size() - l - r;

        unordered_set<string> res;
        dfs(s, 0, rem_left, rem_right, "", res);
        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(const string& s, int index, int rem_left, int rem_right,
             const string& cur, unordered_set<string>& res){

        if(cur.size() == maxlen){
            if(!rem_left && !rem_right)
                res.insert(cur);
            return;
        }

        if(index == n || cur.size() > maxlen)
            return;

        if(s[index] != '(' && s[index] != ')')
            dfs(s, index + 1, rem_left, rem_right, cur + s[index], res);
        else if(s[index] == '('){
            if(rem_left)
                dfs(s, index + 1, rem_left - 1, rem_right, cur + s[index], res);
            dfs(s, index + 1, rem_left, rem_right, cur, res);
        }
        else{
            if(rem_right && rem_right > rem_left)
                dfs(s, index + 1, rem_left, rem_right - 1, cur + s[index], res);
            dfs(s, index + 1, rem_left, rem_right, cur, res);
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

    string s7 = "(()";
    print_vec(Solution().removeInvalidParentheses(s7));
    // 2

    return 0;
}