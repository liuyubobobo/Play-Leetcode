/// Source : https://leetcode.com/problems/find-eventual-safe-states/
/// Author : liuyubobobo
/// Time   : 2021-08-05

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// 反图拓扑排序
/// Time Complexity: O(n)
/// Space Compexity: O(n)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {

        int n = g.size();

        vector<vector<int>> rg(n);
        vector<int> indegrees(n, 0);
        for(int u = 0; u < n; u ++)
            for(int v: g[u]){
                rg[v].push_back(u);
                indegrees[u] ++;
            }

        queue<int> q;
        vector<bool> visited(n, false);
        for(int u = 0; u < n; u ++)
            if(indegrees[u] == 0){
                q.push(u);
                visited[u] = true;
            }

        vector<int> res;
        while(!q.empty()){
            int u = q.front(); q.pop();

            res.push_back(u);

            for(int v: rg[u])
                if(!visited[v]){
                    indegrees[v] --;
                    if(indegrees[v] == 0){
                        q.push(v);
                        visited[v] = true;
                    }
                }
        }

        sort(res.begin(), res.end());
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << endl;
}

int main() {

    vector<vector<int>> g1 = {
            {1,2},{2,3},{5},{0},{5},{},{}
    };
    print_vec(Solution().eventualSafeNodes(g1));
    // 2 4 5 6

    vector<vector<int>> g2 = {
            {1,2,3,4},{1,2},{3,4},{0,4},{}
    };
    print_vec(Solution().eventualSafeNodes(g2));
    // 4

    vector<vector<int>> g3 = {
            {0},{2,3,4},{3,4},{0,4},{}
    };
    print_vec(Solution().eventualSafeNodes(g3));
    // 4

    return 0;
}
