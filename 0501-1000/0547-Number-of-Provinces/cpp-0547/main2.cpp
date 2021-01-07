/// Source : https://leetcode.com/problems/number-of-provinces/
/// Author : liuyubobobo
/// Time   : 2021-01-06

#include <iostream>
#include <vector>

using namespace std;


/// UF
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class UF{

private:
    vector<int> parent;
    int sz;

public:
    UF(int n) : parent(n), sz(n){
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
        sz --;
    }

    int size(){
        return sz;
    }
};

class Solution {

public:
    int findCircleNum(vector<vector<int>>& M) {

        int n = M.size();
        UF uf(n);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                if(M[i][j]) uf.unionElements(i, j);
        return uf.size();
    }
};


int main() {

    return 0;
}
