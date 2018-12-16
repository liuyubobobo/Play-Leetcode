/// Source : https://leetcode.com/problems/regions-cut-by-slashes/
/// Author : liuyubobobo
/// Time   : 2018-12-16

#include <iostream>
#include <vector>

using namespace std;


/// Union-Find
/// Time Complexity: O(4 * m * n)
/// Space Complexity: O(4 * m * n)
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

private:
    const int d[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int m, n;

public:
    int regionsBySlashes(vector<string>& grid) {

        m = grid.size(), n = grid[0].size();

        UF uf(m * n * 4);
        for(int r = 0; r < m; r ++)
            for(int c = 0; c < n; c ++)
                for(int k = 0; k < 4; k ++){
                    if(grid[r][c] == '/')
                        uf.unionElements(id(r, c, k), id(r, c, k < 2 ? 1 - k : 5 - k));
                    else if(grid[r][c] == '\\')
                        uf.unionElements(id(r, c, k), id(r, c, 3 - k));
                    else
                        for(int kk = 0; kk < 4; kk ++)
                            uf.unionElements(id(r, c, k), id(r, c, kk));

                    int nextr = r + d[k][0], nextc = c + d[k][1];
                    if(in_area(nextr, nextc))
                        uf.unionElements(id(r, c, k), id(nextr, nextc, k % 2 ? 4 - k : 2 - k));
                }
        return uf.size();
    }

private:
    int id(int r, int c, int k){
        return r * n * 4 + c * 4 + k;
    }

    bool in_area(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


int main() {

    return 0;
}