/// Source : https://leetcode.com/problems/longest-path-with-different-adjacent-characters/
/// Author : liuyubobobo
/// Time   : 2022-04-16

#include <iostream>
#include <vector>

using namespace std;


/// DFS - One Pass
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int longestPath(vector<int>& parent, string s) {

        int n = parent.size();
        vector<vector<int>> g(n);
        for(int u = 1; u < n; u ++){
            int v = parent[u];
            g[u].push_back(v), g[v].push_back(u);
        }

        int res = 0;
        dfs(g, 0, -1, s, res);
        return res;
    }

private:
    int dfs(const vector<vector<int>>& g, int u, int p, const string& s,
              int& res){

        vector<int> len;
        int maxl = 1;
        for(int v: g[u]){
            if(v == p) continue;
            int l = dfs(g, v, u, s, res);
            if(s[u] != s[v]){
                len.push_back(l);
                maxl = max(maxl, 1 + l);
            }
        }

        if(len.size() == 0)
            res = max(res, 1);
        else if(len.size() == 1)
            res = max(res, len[0] + 1);
        else{
            sort(len.begin(), len.end(), greater<int>());
            res = max(res, len[0] + len[1] + 1);
        }
        return maxl;
    }
};


int main() {

    vector<int> parent1 = {-1,0,0,1,1,2};
    string s1 = "abacbe";
    cout << Solution().longestPath(parent1, s1) << '\n';
    // 3

    vector<int> parent2 = {-1,0,0,0};
    string s2 = "aabc";
    cout << Solution().longestPath(parent2, s2) << '\n';
    // 3

    return 0;
}
