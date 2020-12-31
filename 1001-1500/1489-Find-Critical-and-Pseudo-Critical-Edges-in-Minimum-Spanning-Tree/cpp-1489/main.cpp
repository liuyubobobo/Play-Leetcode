/// Source : https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
/// Author : liuyubobobo
/// Time   : 2020-06-20

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// MST
/// Time Complexity: O(E * ElogE)
/// Space Complexity: O(E)
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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        unordered_map<int, int> index_map;
        for(int i = 0; i < edges.size(); i ++)
            index_map[edges[i][0] * n + edges[i][1]] = i;

        sort(edges.begin(), edges.end(), [](const vector<int>& e1, const vector<int>& e2){
            return e1[2] < e2[2];
        });

        vector<vector<int>> res(2);
        int minW = minimum_tree(edges, n, -1, -1);
        for(int i = 0; i < edges.size(); i ++){
            int index = index_map[edges[i][0] * n + edges[i][1]];
            if(minimum_tree(edges, n, i, -1) > minW)
                res[0].push_back(index);
            else if(minimum_tree(edges, n, -1, i) == minW)
                res[1].push_back(index);
        }
        return res;
    }

private:
    int minimum_tree(const vector<vector<int>>& edges, int n, int del_index, int use_index){

        UF uf(n);
        int res = 0, e_num = 0;

        if(use_index != -1)
            uf.unionElements(edges[use_index][0], edges[use_index][1]),
            e_num ++,
            res += edges[use_index][2];

        for(int i = 0; i < edges.size(); i ++)
            if(i != del_index && !uf.isConnected(edges[i][0], edges[i][1]))
                uf.unionElements(edges[i][0], edges[i][1]),
                e_num ++,
                res += edges[i][2];

        return e_num == n - 1 ? res : INT_MAX;
    }
};


int main() {

    return 0;
}
