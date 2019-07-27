/// Source : https://leetcode.com/problems/connecting-cities-with-minimum-cost/
/// Author : liuyubobobo
/// Time   : 2019-07-25

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Kruskal
/// Time Complexity: O(ElogE)
/// Space Complexity: O(V)
class UF{

private:
    vector<int> parent;
    int sz;

public:
    UF(int n){
        for(int i = 0 ; i < n ; i ++)
            parent.push_back(i);
        sz = n;
    }

    int find(int p){
        if( p != parent[p] )
            parent[p] = find( parent[p] );
        return parent[p];
    }

    bool isConnected(int p , int q){
        return find(p) == find(q);
    }

    void unionElements(int p, int q){

        int pRoot = find(p);
        int qRoot = find(q);

        if( pRoot == qRoot )
            return;

        parent[pRoot] = qRoot;
        sz --;
    }

    int size(){
        return sz;
    }
};

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {

        vector<unordered_map<int, int>> g(N);
        for(vector<int>& c: connections){
            g[--c[0]].count(--c[1]);
            if(!g[c[0]].count(c[1]) || c[2] < g[c[0]][c[1]]){
                g[c[0]][c[1]] = c[2];
                g[c[1]][c[0]] = c[2];
            }
        }

        sort(connections.begin(), connections.end(),
             [](const vector<int>& e1, const vector<int>& e2){
                 return e1[2] < e2[2];
        });

        int res = 0;
        UF uf(N);
        for(const vector<int>& e: connections)
            if(!uf.isConnected(e[0], e[1])){
                uf.unionElements(e[0], e[1]);
                res += e[2];
            }
        return uf.size() == 1 ? res : -1;
    }
};


int main() {

    vector<vector<int>> edges1 = {{1, 2, 5}, {1, 3, 6}, {2, 3, 1}};
    cout << Solution().minimumCost(3, edges1) << endl;
    return 0;
}