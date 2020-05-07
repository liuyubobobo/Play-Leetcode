/// Source : https://leetcode.com/problems/brace-expansion/
/// Author : liuyubobobo
/// Time   : 2020-05-07

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// DFS
/// Using vector to store result and sorting at last
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<string> expand(string s) {

        vector<string> res = expand(s, 0, s.size() - 1);
        sort(res.begin(), res.end());
        return res;
    }

private:
    vector<string> expand(const string& s, int l, int r){

        if(l > r) return {};

        vector<string> a, b;
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

    vector<string> mul(const vector<string>& a, const vector<string>& b){

        if(a.empty()) return b;
        if(b.empty()) return a;

        vector<string> res;
        for(const string& s1: a)
            for(const string& s2: b)
                res.push_back(s1 + s2);
        return res;
    }

    vector<string> split(const string& s, int l, int r){
        vector<string> res;
        for(int start = l, i = start + 1; i <= r + 1; i ++)
            if(i == r + 1 || s[i] == ','){
                res.push_back(s.substr(start, i - start));
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