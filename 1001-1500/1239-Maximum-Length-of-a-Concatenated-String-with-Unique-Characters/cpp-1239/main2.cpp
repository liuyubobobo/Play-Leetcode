/// Source : https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
/// Author : liuyubobobo
/// Time   : 2019-11-08

#include <iostream>
#include <vector>

using namespace std;


/// DFS and using bit
/// Time Complexity: O(2^n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxLength(vector<string>& arr) {

        vector<int> v, lens;
        for(const string& s: arr){
            int x = get_num(s);
            if(x >= 0){
                v.push_back(x);
                int len = 0;
                while(x) len += x & 1, x >>= 1;
                lens.push_back(len);
            }
        }

        return dfs(v, lens, 0, 0);
    }

private:
    int dfs(const vector<int>& v, const vector<int>& lens, int index, int cur){

        if(index == v.size()) return 0;

        int res = dfs(v, lens, index + 1, cur);

        if(!(cur & v[index]))
            res = max(res, lens[index] + dfs(v, lens, index + 1, cur | v[index]));
        return res;
    }

    int get_num(const string& s){

        int x = 0;
        for(char c: s) {
            if (x & (1 << (c - 'a'))) return -1;
            x += (1 << (c - 'a'));
        }
        return x;
    }
};


int main() {

    return 0;
}