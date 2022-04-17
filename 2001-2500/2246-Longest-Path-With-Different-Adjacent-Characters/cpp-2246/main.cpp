/// Source : https://leetcode.com/problems/longest-path-with-different-adjacent-characters/
/// Author : liuyubobobo
/// Time   : 2022-04-16

#include <iostream>
#include <vector>

using namespace std;


/// DFS - Two Pass
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

        vector<int> dp1(n, 1);
        dfs1(g, 0, -1, s, dp1);

//        for(int e: dp1) cout << e << ' '; cout << '\n';

        int res = 1;
        dfs2(g, 0, -1, dp1, s, res);
        return res;
    }

private:
    void dfs2(const vector<vector<int>>& g, int u, int p, const vector<int>& dp, const string& s,
              int& res){

        vector<int> len;
        for(int v: g[u]){
            if(v == p) continue;
            dfs2(g, v, u, dp, s, res);
            if(s[u] != s[v])
                len.push_back(dp[v]);
        }

        if(len.size() == 0)
            res = max(res, 1);
        else if(len.size() == 1)
            res = max(res, len[0] + 1);
        else{
            sort(len.begin(), len.end(), greater<int>());
            res = max(res, len[0] + len[1] + 1);
        }
    }

    void dfs1(const vector<vector<int>>& g, int u, int p, const string& s,
              vector<int>& dp){

        int res = 1;
        for(int v: g[u]){
            if(v == p) continue;

            dfs1(g, v, u, s, dp);
            if(s[v] != s[u])
                res = max(res, 1 + dp[v]);
        }
        dp[u] = res;
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
