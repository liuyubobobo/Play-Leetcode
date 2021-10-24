/// Source : https://leetcode.com/problems/count-nodes-with-the-highest-score/
/// Author : liuyubobobo
/// Time   : 2021-10-23

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {

        int n = parents.size();
        vector<vector<int>> g(n);
        for(int u = 1; u < n; u ++){
            int v = parents[u];
            g[v].push_back(u);
        }

        vector<int> sz(n, 0);
        dfs_sz(g, 0, sz);

        long long max_score = -1;
        int max_score_f = 0;
        dfs(n, g, 0, sz, max_score, max_score_f);
        return max_score_f;
    }

private:
    void dfs(int n, const vector<vector<int>>& g, int u, const vector<int>& sz,
             long long& max_score, int& max_score_f){

        long long score = 1;
        int count = 1;
        for(int v: g[u]){
            score *= sz[v];
            count += sz[v];
        }
        if(n - count) score *= (n - count);

        if(score > max_score) max_score = score, max_score_f = 1;
        else if(score == max_score) max_score_f ++;

        for(int v: g[u])
            dfs(n, g, v, sz, max_score, max_score_f);
    }

    void dfs_sz(const vector<vector<int>>& g, int u, vector<int>& sz){

        sz[u] = 1;
        for(int v: g[u]){
            dfs_sz(g, v, sz);
            sz[u] += sz[v];
        }
    }
};


int main() {

    return 0;
}
