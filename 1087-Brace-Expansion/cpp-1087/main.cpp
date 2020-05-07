/// Source : https://leetcode.com/problems/brace-expansion/
/// Author : liuyubobobo
/// Time   : 2020-05-07

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// DFS
/// Using TreeSet to keep order
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<string> expand(string s) {

        set<string> res = expand(s, 0, s.size() - 1);
        return vector<string>(res.begin(), res.end());
    }

private:
    set<string> expand(const string& s, int l, int r){

        if(l > r) return {};

        set<string> a, b;
        int i;
        if(s[l] == '{'){
            for(i = l + 1; i <= r; i ++)
                if(s[i] == '}'){
                    a = split(s, l + 1, i - 1);
                    break;
                }
            b = expand(s, i + 1, r);
            return mul(a, b);
        }

        for(i = l; i <= r; i ++)
            if(s[i] == '{') break;

        a = split(s, l, i - 1);
        b = expand(s, i, r);
        return mul(a, b);
    }

    set<string> mul(const set<string>& a, const set<string>& b){

        if(a.empty()) return b;
        if(b.empty()) return a;

        set<string> res;
        for(const string& s1: a)
            for(const string& s2: b)
                res.insert(s1 + s2);
        return res;
    }

    set<string> split(const string& s, int l, int r){
        set<string> res;
        for(int start = l, i = start + 1; i <= r + 1; i ++)
            if(i == r + 1 || s[i] == ','){
                res.insert(s.substr(start, i - start));
                start = i + 1;
                i = start;
            }
        return res;
    }
};


void print_vec(const vector<string>& vec){

    for(const string& e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    print_vec(Solution().expand("{a,b}c{d,e}f"));
    // "acdf","acef","bcdf","bcef"

    print_vec(Solution().expand("abcd"));
    // abcd

    print_vec(Solution().expand("k{a,b,c,d,e,f,g}"));

    return 0;
}