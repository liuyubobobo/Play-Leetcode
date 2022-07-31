/// Source : https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
/// Author : liuyubobobo
/// Time   : 2022-07-31

#include <iostream>
#include <vector>

using namespace std;


/// Find Cycle in Successor Graph
/// DFS is ok but I think using UF is more elegant:)
/// Time Compelxity: O(n)
/// Space Compelxity: O(n)
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

    bool is_connected(int p, int q){
        return find(p) == find(q);
    }

    void union_elements(int p, int q){

        int p_root = find(p), q_root = find(q);

        if(p_root == q_root) return;

        parent[p_root] = q_root;
    }
};

class Solution {
public:
    int longestCycle(vector<int>& g) {

        int n = g.size();
        UF uf(n);

        int res = -1;
        for(int i = 0; i < n; i ++){

            if(g[i] == -1) continue;

            if(!uf.is_connected(i, g[i])){
                uf.union_elements(i, g[i]);
                continue;
            }

            int tres = 1, cur = g[i];
            while(cur != i){
                tres ++;
                cur = g[cur];
            }
            res = max(res, tres);
        }
        return res;
    }
};


int main() {

    return 0;
}
