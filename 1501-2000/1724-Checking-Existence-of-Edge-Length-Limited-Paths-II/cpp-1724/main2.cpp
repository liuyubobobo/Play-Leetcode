/// Source : https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii/
/// Author : liuyubobobo
/// Time   : 2021-01-14

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// LCA
/// Time Complexity: init: O(ElogE + V)
///                  query: O(logV)
/// Space Comoplexity: O(V + E)
class UF{

private:
    vector<int> parent;

public:
    UF(int n) : parent(n){
        for(int i = 0 ; i < n ; i ++)
            parent[i] = i;
    }

    int find(int p){
        if(p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }

    bool isConnected(int p, int q){
        return find(p) == find(q);
    }

    void unionElements(int p, int q){

        int pRoot = find(p), qRoot = find(q);

        if(pRoot == qRoot) return;

        parent[pRoot] = qRoot;
    }
};

class DistanceLimitedPathsExist {

private:
    UF uf;

    const int L;
    vector<vector<int>> up, limits;
    vector<unordered_map<int, int>> tree;

    vector<int> tin, tout;
    int timer = 0;

public:
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edges) : uf(n),
        L((int)ceil(log2(n))), tree(n), tin(n, -1), tout(n),
        up(n, vector<int>(L + 1)), limits(n, vector<int>(L + 1)){

        sort(edges.begin(), edges.end(), [](const vector<int>& e1, const vector<int>& e2){
            return e1[2] < e2[2];
        });

        for(const vector<int>& e: edges)
            if(!uf.isConnected(e[0], e[1])){
                uf.unionElements(e[0], e[1]);

                tree[e[0]][e[1]] = e[2];
                tree[e[1]][e[0]] = e[2];
            }

        timer = 0;
        for(int u = 0; u < n; u ++)
            if(tin[u] < 0)
                dfs(u, u);
    }

    bool query(int p, int q, int limit) {

        if(!uf.isConnected(p, q)) return false;

        int x = lca(p, q);

        for(int i = L; i >= 0; i --)
            if(is_ancestor(x, up[p][i]) ){
                if(limits[p][i] >= limit) return false;
                p = up[p][i];
            }

        for(int i = L; i >= 0; i --)
            if(is_ancestor(x,up[q][i])){
                if(limits[q][i] >= limit) return false;
                q = up[q][i];
            }

        return true;
    }

private:
    void dfs(int u, int p){

        tin[u] = timer ++;
        up[u][0] = p;
        limits[u][0] = u == p ? 0 : tree[p][u];
        for(int i = 1; i <= L; i ++)
            up[u][i] = up[up[u][i - 1]][i - 1],
            limits[u][i] = max(limits[u][i - 1], limits[up[u][i - 1]][i - 1]);

        for(const pair<int, int>& pa: tree[u]){
            int v = pa.first;
            if(v != p){
                tree[v].erase(u);
                dfs(v, u);
            }
        }

        tout[u] = timer ++;
    }

    bool is_ancestor(int u, int v){
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int lca(int u, int v){

        if(is_ancestor(u, v)) return u;
        if(is_ancestor(v, u)) return v;

        for(int i = L; i >= 0; i --)
            if(!is_ancestor(up[u][i], v))
                u = up[u][i];
        return up[u][0];
    }
};


int main() {

    vector<vector<int>> edges1 = {{0, 2, 4}, {0, 3, 2}, {1, 2, 3}, {2, 3, 1}, {4, 5, 5}};
    DistanceLimitedPathsExist obj1(6, edges1);
    cout << obj1.query(2, 3, 2) << endl; // 1
    cout << obj1.query(1, 3, 3) << endl; // 0
    cout << obj1.query(2, 0, 3) << endl; // 1
    cout << obj1.query(0, 5, 6) << endl; // 0

    cout << endl;

    vector<vector<int>> edges2 = {{1, 0, 3}, {1, 0, 5}, {1, 2, 1}, {1, 0, 2}, {2, 0, 1}, {0, 1, 3}};
    DistanceLimitedPathsExist obj2(3, edges2);
    cout << obj2.query(2, 1, 5) << endl; // 1
    cout << obj2.query(1, 0, 5) << endl; // 1
    cout << obj2.query(2, 1, 3) << endl; // 1

    cout << endl;

    vector<vector<int>> edges3 = {{0, 1, 3}, {0, 1, 3}, {0, 1, 4}, {0, 1, 1}, {1, 0, 5}, {1, 0, 3}};
    DistanceLimitedPathsExist obj3(2, edges3);
    cout << obj3.query(1, 0, 4) << endl; // 1
    cout << obj3.query(1, 0, 1) << endl; // 0

    return 0;
}
