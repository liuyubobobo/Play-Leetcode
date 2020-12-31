/// Source : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
/// Author : liuyubobobo
/// Time   : 2018-11-25

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Using Union-Find to calculate connected components
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class UF{

private:
    vector<int> parent, sz;

public:
    UF(int n): sz(n, 1){
        for(int i = 0 ; i < n ; i ++)
            parent.push_back(i);
    }

    int find(int p){
        if(p != parent[p])
            parent[p] = find(parent[p]);
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
        sz[qRoot] += sz[pRoot];
    }

    int size(int p){
        return sz[find(p)];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        UF uf(n);
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    uf.unionElements(i, j);

        int res = 0;
        unordered_set<int> groups;
        for(int i = 0; i < n; i ++){
            int group = uf.find(i);
            if(!groups.count(group)){
                res += uf.size(i) - 1;
                groups.insert(group);
            }
        }

        return res;
    }
};


int main() {

    vector<vector<int>> stones1 = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << Solution().removeStones(stones1) << endl;
    // 5

    vector<vector<int>> stones2 = {{0,0},{0,2},{1,1},{2,0},{2,2}};
    cout << Solution().removeStones(stones2) << endl;
    // 3

    vector<vector<int>> stones3 = {{0,0}};
    cout << Solution().removeStones(stones3) << endl;
    // 0

    return 0;
}