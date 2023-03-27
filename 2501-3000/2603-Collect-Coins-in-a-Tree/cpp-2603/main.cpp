/// Source : https://leetcode.com/problems/collect-coins-in-a-tree/description/
/// Author : liuyubobobo
/// Time   : 2023-03-26

#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;


/// BFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {

        int n = coins.size();
        vector<list<int>> tree(n);

        for(const vector<int>& edge : edges){
            int u = edge[0], v = edge[1];
            tree[u].push_back(v), tree[v].push_back(u);
        }

        vector<bool> mask = prune(n, tree, coins);

        vector<int> d(n, 0);
        for(const vector<int>& edge : edges){
            int u = edge[0], v = edge[1];
            if(mask[u] && mask[v]) d[u] ++, d[v] ++;
        }

        queue<int> q;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++)
            if(d[i] == 1) q.push(i), visited[i] = true;

        vector<int> dis(n, 0);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v: tree[u]){
                if(visited[v] || !mask[v]) continue;
                if(coins[u] || dis[u]) dis[v] = max(dis[v], dis[u] + 1);
                d[v] --;
                if(d[v] == 1) q.push(v), visited[v] = true;
            }
        }

        int root = -1;
        for(int i = 0; i < n; i++)
            if(dis[i] >= 2){root = i; break;}

        return root == -1 ? 0 : dfs(tree, root, -1, dis);
    }

private:
    int dfs(const vector<list<int>>& tree, int u, int p, const vector<int>& value){

        int res = 0;
        for(int v: tree[u]){
            if(v == p || value[v] < 2) continue;
            res += 2 + dfs(tree, v, u, value);
        }

        return res;
    }

    vector<bool> prune(int n, vector<list<int>>& tree, const vector<int>& coins){

        vector<int> d(n, 0);
        for(int i = 0; i < n; i++) d[i] = tree[i].size();

        queue<int> q;
        for(int i = 0; i < n; i++)
            if(d[i] == 1 && coins[i] == 0) q.push(i);

        vector<bool> mask(n, true);
        while(!q.empty()){
            int u = q.front(); q.pop();
            mask[u] = false;

            for(int v: tree[u]){
                if(!mask[v] || coins[v]) continue;
                d[v] --;
                if(d[v] == 1) q.push(v);
            }
        }
        return mask;
    }
};


int main() {

    vector<int >coins1 = {1,0,0,0,0,1};
    vector<vector<int>> edges1 = {{0,1},{1,2},{2,3},{3,4},{4,5}};
    cout << Solution().collectTheCoins(coins1, edges1) << endl;
    // 2

    vector<int> coins2 = {0,0,0,1,1,0,0,1};
    vector<vector<int>> edges2 = {{0,1},{0,2},{1,3},{1,4},{2,5},{5,6},{5,7}};
    cout << Solution().collectTheCoins(coins2, edges2) << endl;
    // 2

    vector<int> coins3 = {1,0,0,1,0,0,1,0,0};
    vector<vector<int>> edges3 = {{0,1},{0,2},{0,3},{1,4},{2,5},{4,6},{2,7},{5,8}};
    cout << Solution().collectTheCoins(coins3, edges3) << endl;
    // 0

    return 0;
}
