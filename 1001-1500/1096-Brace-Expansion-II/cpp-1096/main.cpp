/// Source : https://leetcode.com/problems/brace-expansion-ii/
/// Author : liuyubobobo
/// Time   : 2019-06-22

#include <iostream>
#include <vector>
#include <set>
#include <cassert>

using namespace std;


/// Recursion
/// Time Complexity: O(n^n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<string> braceExpansionII(string exp) {

        set<string> res = braceExpansion(exp, 0, exp.size() - 1);
        return vector<string>(res.begin(), res.end());
    }

private:
    set<string> braceExpansion(const string& exp, int l, int r) {

        if(l > r) return {};

        if(hasComma(exp, l, r)){

            set<string> res;
            int stack = 0;
            for(int start = l, i = l; i <= r + 1; i ++)
                if(i == r + 1 || (exp[i] == ',' && !stack)){
                    res = add(res, braceExpansion(exp, start, i - 1));
                    start = i + 1;
                    i = start - 1;
                }
                else if(exp[i] == '{') stack ++;
                else if(exp[i] == '}') stack --;
            return res;
        }

        if(exp[l] == '{'){
            int next = get_next(exp, l);
            set<string> a = braceExpansion(exp, l + 1, next - 1);
            if(next == r) return a;
            else if(exp[next + 1] == ',')
                return add(a, braceExpansion(exp, next + 2, r));
            else
                return mul(a, braceExpansion(exp, next + 1, r));
        }

        string e = "";
        while(l <= r && isalpha(exp[l]))
            e += exp[l ++];

        set<string> a = {e};
        l --;

        if(l == r) return a;

        if(exp[l + 1] == '{'){

            int next = get_next(exp, l + 1);
            set<string> res = mul(a, braceExpansion(exp, l + 1, next));

            if(next == r) return res;
            else if(exp[next + 1] == ',')
                return add(res, braceExpansion(exp, next + 2, r));
            else
                return mul(res, braceExpansion(exp, next + 1, r));
        }
        else{
            assert(exp[l + 1] == ',');
            return add(a, braceExpansion(exp, l + 2, r));
        }

        assert(false);
        return {};
    }

    bool hasComma(const string& exp, int l, int r){

        int stack = 0;
        for(int i = l; i <= r; i ++)
            if(exp[i] == '{') stack ++;
            else if(exp[i] == '}') stack --;
            else if(exp[i] == ',' && !stack) return true;
        return false;
    }

    set<string> mul(const set<string>& a, const set<string>& b){
        set<string> res;
        for(const string& e1: a)
            for(const string& e2: b)
                res.insert(e1 + e2);
        return res;
    }

    set<string> add(const set<string>& a, const set<string>& b){
        set<string> res = a;
        for(const string& e: b)
            res.insert(e);
        return res;
    }

    int get_next(const string& exp, int start){

        assert(exp[start] == '{');
        int stack = 1;
        for(int i = start + 1; i < exp.size(); i ++)
            if(exp[i] == '{') stack ++;
            else if(exp[i] == '}'){
                stack --;
                if(!stack) return i;
            }
        return exp.size();
    }
};


void print_vec(const vector<string>& vec){
    for(const string& e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    print_vec(Solution().braceExpansionII("{a,b}{c{d,e}}"));
    print_vec(Solution().braceExpansionII("{{a,z},a{b,c},{ab,z}}"));
    print_vec(Solution().braceExpansionII("{a,b}c{d,e}f"));
    print_vec(Solution().braceExpansionII("{a{x,ia,o}w,{n,{g{u,o}},{a,{x,ia,o},w}},er}"));
    // ["a","aiaw","aow","axw","er","go","gu","ia","n","o","w","x"]

    return 0;
}