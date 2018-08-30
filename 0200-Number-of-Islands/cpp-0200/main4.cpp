/// Source : https://leetcode.com/problems/number-of-islands/description/
/// Author : liuyubobobo
/// Time   : 2018-08-26

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>

using namespace std;

/// Using union-find
/// Time Complexity: O(n*m)
/// Space Complexity: O(n*m)
class UnionFind{

private:
    vector<int> rank, parent;

public:
    UnionFind(int n){
        rank.clear();
        parent.clear();
        for( int i = 0 ; i < n ; i ++ ){
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int p){
        while(p != parent[p]){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool isConnected(int p , int q){
        return find(p) == find(q);
    }

    void unionElements(int p, int q){

        int pRoot = find(p);
        int qRoot = find(q);

        if(pRoot == qRoot)
            return;

        if(rank[pRoot] < rank[qRoot])
            parent[pRoot] = qRoot;
        else if(rank[qRoot] < rank[pRoot])
            parent[qRoot] = pRoot;
        else{ // rank[pRoot] == rank[qRoot]
            parent[pRoot] = qRoot;
            rank[qRoot] += 1;
        }
    }
};

class Solution {

private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

public:
    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        if(m == 0)
            return 0;
        n = grid[0].size();
        if(n == 0)
            return 0;

        UnionFind uf(m * n);
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(grid[i][j] == '1')
                    for(int k = 0; k < 4; k ++){
                        int newX = i + d[k][0];
                        int newY = j + d[k][1];
                        if(inArea(newX, newY) && grid[newX][newY] == '1')
                            uf.unionElements(i * n + j, newX * n + newY);
                    }

        unordered_set<int> regions;
        for(int i = 0 ; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(grid[i][j] == '1')
                    regions.insert(uf.find(i * n + j));
        return regions.size();
    }

private:
    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


int main() {

    vector<vector<char>> grid1 = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
    };
    cout << Solution().numIslands(grid1) << endl;
    // 1

    // ---

    vector<vector<char>> grid2 = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
    };
    cout << Solution().numIslands(grid2) << endl;
    // 3

    return 0;
}