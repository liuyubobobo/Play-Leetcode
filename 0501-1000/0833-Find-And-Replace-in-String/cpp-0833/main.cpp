/// Source : https://leetcode.com/problems/find-and-replace-in-string/
/// Author : liuyubobobo
/// Time   : 2023-08-14

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;


class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {

        int n = indices.size();
        vector<tuple<int, string, string>> v(n);
        for(int i = 0; i < n; i ++) v[i] = make_tuple(indices[i], sources[i], targets[i]);
        sort(v.begin(), v.end());

        int offset = 0;
        for(int i = 0; i < n; i ++){
            int index = get<0>(v[i]);
            string a = get<1>(v[i]), b = get<2>(v[i]);
            if(s.find(a, index + offset) == index + offset){
                s.replace(index + offset, a.size(), b);
                offset += b.size() - a.size();
            }
        }
        return s;
    }
};


int main() {

    return 0;
}
