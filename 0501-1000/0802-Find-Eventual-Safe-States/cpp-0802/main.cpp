/// Source : https://leetcode.com/problems/find-eventual-safe-states/
/// Author : liuyubobobo
/// Time   : 2021-08-05

#include <iostream>
#include <vector>

using namespace std;


/// 有向图寻环 modified
/// Time Complexity: O(n)
/// Space Compexity: O(n)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {

        int n = g.size();
        vector<bool> visited(n, false), instack(n, false), in_circle(n, false);
        vector<int> from(n, -1);
        for(int i = 0; i < n; i ++)
            if(!visited[i])
                dfs(g, i, -1, visited, instack, from, in_circle);

        vector<int> res;
        for(int v = 0; v < n; v ++)
            if(!in_circle[v]) res.push_back(v);
        return res;
    }

private:
    bool dfs(const vector<vector<int>>& g, int u, int p,
             vector<bool>& visited, vector<bool>& instack, vector<int>& from, vector<bool>& in_circle){

        visited[u] = true;
        instack[u] = true;

        from[u] = p;

        bool ret = false;
        for(int v: g[u])
            if(!visited[v]){
                if(dfs(g, v, u, visited, instack, from, in_circle))
                    ret = true;
            }
            else if(instack[v]){
                in_circle[v] = true;
                int cur = u;
                while(cur != v){
                    in_circle[cur] = true;
                    cur = from[cur];
                }
                ret = true;
            }
            else if(in_circle[v]){
                ret = true;
            }

        instack[u] = false;

        if(ret) in_circle[u] = true;
        return ret;
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
