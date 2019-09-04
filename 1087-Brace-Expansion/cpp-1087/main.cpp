#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    vector<string> expand(string s) {

        set<string> res = expand(s, 0, s.size() - 1);
        return vector<string>(res.begin(), res.end());
    }

private:
    set<string> expand(const string& s, int l, int r){

        if(l > r) return {};

        set<string> a;
        if(s[l] == '{'){
            int i;
            for(i = l + 1; i <= r; i ++)
                if(s[i] == '}'){
                    a = expand(s, l + 1, i - 1);
                    break;
                }
            set<string> b = expand(s, i + 1, r);
            return mul(a, b);
        }

        string e = "";
        while(l <= r && isalpha(s[l]))
                e += s[l ++];
        a = {e};
        if(l > r) return a;

        if(s[l] == '{') return mul(a, expand(s, l, r));

        assert(s[l] == ',');
        return add(a, expand(s, l + 1, r));
    }

    set<string> mul(const set<string>& a, const set<string>& b){
        set<string> res;
        for(const string& s1: a)
            for(const string& s2: b)
                res.insert(s1 + s2);
        return res;
    }

    set<string> add(const set<string>& a, const set<string>& b){
        set<string> res = a;
        for(const string& s: b)
            res.insert(s);
        return res;
    }
};


void print_vec(const vector<string>& vec){

    for(const string& e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

//    print_vec(Solution().expand("{a,b}c{d,e}f"));
//    print_vec(Solution().expand("abcd"));
    print_vec(Solution().expand("k{a,b,c,d,e,f,g}"));

    return 0;
}