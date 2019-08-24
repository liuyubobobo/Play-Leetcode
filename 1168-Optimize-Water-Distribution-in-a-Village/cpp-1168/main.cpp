/// Source : https://leetcode.com/problems/optimize-water-distribution-in-a-village/
/// Author : liuyubobobo
/// Time   : 2019-08-24

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// MST
/// Time Complexity: O(ElogE)
/// Space Complexity: O(V + E)
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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {

        for(int i = 0; i < wells.size(); i ++)
            pipes.push_back({0, i + 1, wells[i]});

        sort(pipes.begin(), pipes.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[2] < v2[2];
        });

        UF uf(n + 1);
        int res = 0;
        for(const vector<int>& v: pipes)
            if(!uf.isConnected(v[0], v[1]))
                res += v[2], uf.unionElements(v[0], v[1]);
        return res;
    }
};


int main() {

    vector<int> wells1 = {1,2,2};
    vector<vector<int>> pipes1 = {{1, 2, 1}, {2, 3, 1}};
    cout << Solution().minCostToSupplyWater(3, wells1, pipes1) << endl;
    // 3

    vector<int> wells2 = {46012,72474,64965,751,33304};
    vector<vector<int>> pipes2 = {{2,1,6719},{3,2,75312},{5,3,44918}};
    cout << Solution().minCostToSupplyWater(5, wells2, pipes2) << endl;
    // 131704

    return 0;
}