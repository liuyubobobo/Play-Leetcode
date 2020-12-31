/// Source : https://leetcode.com/problems/parsing-a-boolean-expression/
/// Author : liuyubobobo
/// Time   : 2019-06-30

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


/// Recursion
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    bool parseBoolExpr(string exp) {

        return parse(exp, 0, exp.size() - 1);
    }

private:
    bool parse(const string& exp, int l, int r){

        if(l == r) return exp[l] == 't' ? true : false;

        if(exp[l] == '!') return !parse(exp, l + 2, r - 1);

        vector<int> comma = get_comma(exp, l + 2, r - 1);

        if(comma.size() == 0) return parse(exp, l + 2, r - 1);

        vector<bool> subs = {parse(exp, l + 2, comma[0] - 1)};
        for(int i = 0; i < comma.size(); i ++)
            subs.push_back(parse(exp, comma[i] + 1, i + 1 == comma.size() ? r - 1 : comma[i + 1] - 1));

        bool res = subs[0];
        if(exp[l] == '&')
            for(int i = 1; i < subs.size(); i ++) res = res && subs[i];
        else
            for(int i = 1; i < subs.size(); i ++) res = res || subs[i];
        return res;
    }

    vector<int> get_comma(const string& exp, int l, int r){

        vector<int> res;
        int stack = 0;
        for(int i = l; i <= r; i ++)
            if(exp[i] == '(') stack ++;
            else if(exp[i] == ')') stack --;
            else if(exp[i] == ',' && !stack) res.push_back(i);
        return res;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    string exp1 = "!(f)";
    print_bool(Solution().parseBoolExpr(exp1));
    // true

    string exp2 = "|(f,t)";
    print_bool(Solution().parseBoolExpr(exp2));
    // true

    string exp3 = "&(t,f)";
    print_bool(Solution().parseBoolExpr(exp3));
    // false

    string exp4 = "|(&(t,f,t),!(t))";
    print_bool(Solution().parseBoolExpr(exp4));
    // false

    string exp5 = "!(&(!(t),&(f),|(f)))";
    print_bool(Solution().parseBoolExpr(exp5));
    // true


    return 0;
}