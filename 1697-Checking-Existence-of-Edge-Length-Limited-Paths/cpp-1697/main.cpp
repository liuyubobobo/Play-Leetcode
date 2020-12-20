/// Source : https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/
/// Author : liuyubobobo
/// Time   : 2020-12-19

#include <iostream>
#include <vector>

using namespace std;


/// Offline: Sort + UF
/// Time Complexity: O(|e|log|e| + |q|log|q| + |q|)
/// Space Complexity: O(n)
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

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {

        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& e1, const vector<int>& e2){
           return e1[2] < e2[2];
        });

        for(int i = 0; i < queries.size(); i ++)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [](const vector<int>& q1, const vector<int>& q2){
            return q1[2] < q2[2];
        });

        UF uf(n);
        vector<bool> res(queries.size());
        int ep = 0;
        for(int i = 0; i < queries.size(); i ++){

            while(ep < edgeList.size() && edgeList[ep][2] < queries[i][2])
                uf.unionElements(edgeList[ep][0], edgeList[ep][1]), ep ++;

            res[queries[i][3]] = uf.isConnected(queries[i][0], queries[i][1]);
        }
        return res;
    }
};


int main() {

    return 0;
}
