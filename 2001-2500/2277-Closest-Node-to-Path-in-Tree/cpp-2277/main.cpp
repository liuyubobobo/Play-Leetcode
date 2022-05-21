/// Source : https://leetcode.com/problems/closest-node-to-path-in-tree/
/// Author : liuyubobobo
/// Time   : 2022-05-20

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;


/// BFS
/// Time Complexity: O(q * n * logn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

        vector<vector<int>> g(n);
        for(const vector<int>& edge: edges){
            int u = edge[0], v = edge[1];
            g[u].push_back(v), g[v].push_back(u);
        }

        vector<int> res;
        for(const vector<int>& q: query){
            int start = q[0], end = q[1], node = q[2];

            set<int> path = get_path(n, g, start, end);
            res.push_back(get_res(n, g, node, path));
        }
        return res;
    }

private:
    int get_res(int n, const vector<vector<int>>& g, int s, const set<int>& t_set){

        if(t_set.size() == 1) return *t_set.begin();

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(t_set.count(u)) return u;

            for(int v: g[u])
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
        }
        assert(false);
        return -1;
    }

    set<int> get_path(int n, const vector<vector<int>>& g, int s, int t){

        if(s == t) return {s};

        vector<int> pre(n, -1);
        queue<int> q;
        q.push(s);
        pre[s] = s;
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;

            for(int v: g[u])
                if(pre[v] == -1){
                    pre[v] = u;
                    q.push(v);
                }
        }

        set<int> path;
        int cur = t;
        while(pre[cur] != cur){
            path.insert(cur);
            cur = pre[cur];
        }
        path.insert(cur);

        return path;
    }
};


int main() {


    return 0;
}
