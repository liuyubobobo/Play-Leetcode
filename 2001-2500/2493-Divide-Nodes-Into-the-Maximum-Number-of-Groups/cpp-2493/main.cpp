/// Source : https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/description/
/// Author : liuyubobobo
/// Time   : 2022-12-22

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;


/// Brute Force
/// Time Complexity: O(V * (V + E))
/// Space Complexity: O(V + E)
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {

        vector<list<int>> g(n);
        for(const vector<int>& e: edges){
            int a = e[0] - 1, b = e[1] - 1;
            g[a].push_back(b), g[b].push_back(a);
        }

        vector<int> cc(n, -1);
        int cc_index = 0, res = 0;
        for(int u = 0; u < n; u ++){
            if(cc[u] != -1) continue;
            dfs(g, u, cc_index, cc);

            int tres = solve(n, g, cc_index, cc);
            if(tres == -1) return -1;
            res += tres;

            cc_index ++;
        }
        return res;
    }

private:
    int solve(int n, const vector<list<int>>& g, int cc_index, const vector<int>& cc){

        int res = -1;
        for(int s = 0; s < n; s ++){
            if(cc[s] != cc_index) continue;
            res = max(res, solve(n, g, s));
        }

        return res;
    }

    int solve(int n, const vector<list<int>>& g, int s){

        vector<int> level(n, -1), pre(n, -1);

        queue<int> q;
        q.push(s);
        level[s] = 1;
        pre[s] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v: g[u]){
                if(level[v] != -1){
                    if(abs(level[v] - level[u]) == 1) continue;
                    else return -1;
                }
                level[v] = level[u] + 1;
                pre[v] = u;
                q.push(v);
            }
        }
        return *max_element(level.begin(), level.end());
    }

    void dfs(const vector<list<int>>& g, int u, int cc_index, vector<int>& cc){

        cc[u] = cc_index;
        for(int v: g[u]){
            if(cc[v] == -1) dfs(g, v, cc_index, cc);
        }
    }
};


int main() {

    vector<vector<int>> edges1 = {
            {1,2},{1,4},{1,5},{2,6},{2,3},{4,6}
    };
    cout << Solution().magnificentSets(6, edges1) << '\n';
    // 4

    return 0;
}
