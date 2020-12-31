/// Source : https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
/// Author : liuyubobobo
/// Time   : 2019-10-26

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(2^n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxLength(vector<string>& arr) {

        vector<string> v;
        for(const string& s: arr)
            if(is_unique(s)) v.push_back(s);

        return dfs(v, 0, "");
    }

private:
    int dfs(const vector<string>& v, int index, const string& cur){

        if(index == v.size()) return 0;

        int res = dfs(v, index + 1, cur);

        if(is_unique(cur + v[index]))
            res = max(res, (int)v[index].size() + dfs(v, index + 1, cur + v[index]));
        return res;
    }

    bool is_unique(const string& s){

        vector<int> visited(26);
        for(char e: s) {
            if (visited[e - 'a']) return false;
            visited[e - 'a'] = true;
        }
        return true;
    }
};


int main() {

    return 0;
}