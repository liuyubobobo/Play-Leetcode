/// Source : https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
/// Author : liuyubobobo
/// Time   : 2020-09-05

#include <iostream>
#include <vector>

using namespace std;


/// Kruskal
/// Time Complexity: O(e)
/// Space Complexity: O(e)
class UF{

private:
    vector<int> parent;

public:
    UF(int n){
        for(int i = 0 ; i < n ; i ++)
            parent.push_back(i);
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
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        int del = 0;

        vector<pair<int, int>> type[3];
        for(const vector<int>& e: edges)
            type[e[0] - 1].push_back({e[1] - 1, e[2] - 1});

        UF uf1(n), uf2(n);
        for(const pair<int, int>& p: type[2])
            if(uf1.isConnected(p.first, p.second)) del ++;
            else{
                uf1.unionElements(p.first, p.second);
                uf2.unionElements(p.first, p.second);
            }

        for(const pair<int, int>& p: type[0])
            if(uf1.isConnected(p.first, p.second)) del ++;
            else uf1.unionElements(p.first, p.second);

        for(const pair<int, int>& p: type[1])
            if(uf2.isConnected(p.first, p.second)) del ++;
            else uf2.unionElements(p.first, p.second);

        for(int i = 1; i < n; i ++) {
            if (!uf1.isConnected(i - 1, i)) return -1;
            if (!uf2.isConnected(i - 1, i)) return -1;
        }
        return del;
    }
};


int main() {

    vector<vector<int>> edges1 = {
            {3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}
    };
    cout << Solution().maxNumEdgesToRemove(4, edges1) << endl;
    // 2

    vector<vector<int>> edges2 = {
            {3,1,2},{3,2,3},{1,1,4},{2,1,4}
    };
    cout << Solution().maxNumEdgesToRemove(4, edges2) << endl;
    // 0

    vector<vector<int>> edges3 = {
            {3,2,3},{1,1,2},{2,3,4}
    };
    cout << Solution().maxNumEdgesToRemove(4, edges3) << endl;
    // -1

    return 0;
}
