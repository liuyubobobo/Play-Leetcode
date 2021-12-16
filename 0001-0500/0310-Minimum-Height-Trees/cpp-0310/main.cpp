/// Source : https://leetcode.com/problems/minimum-height-trees/
/// Author : liuyubobobo
/// Time   : 2021-12-15

#include <iostream>
#include <vector>

using namespace std;


/// Tree Centroids
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<vector<int>> g(n);
        for(const vector<int>& e: edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        return get_tree_centroid(n, g);
    }

private:
    vector<int> get_tree_centroid(int n, const vector<vector<int>>& g){

        vector<int> degrees(n, 0);
        vector<int> leaves;
        for(int u = 0; u < n; u ++){
            degrees[u] = g[u].size();
            if(degrees[u] == 0 || degrees[u] == 1){
                leaves.push_back(u);
                degrees[u] = 0;
            }
        }

        int count = leaves.size();
        while(count < n){
            vector<int> new_leaves;
            for(int u: leaves){
                for(int v: g[u]){
                    degrees[v] --;
                    if(degrees[v] == 1) new_leaves.push_back(v);
                }
                degrees[u] = 0;
            }
            count += new_leaves.size();
            leaves = new_leaves;
        }
        assert(1 <= leaves.size() && leaves.size() <= 2);
        return leaves;
    }
};


int main() {

    return 0;
}
