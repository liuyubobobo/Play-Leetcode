/// Source : https://leetcode.com/problems/number-of-islands/description/
/// Author : liuyubobobo
/// Time   : 2018-08-26

import java.util.Arrays;
import java.util.HashSet;

/// Using Union-Find
/// Time Complexity: O(n*m)
/// Space Complexity: O(n*m)
class Solution3 {

    private class UnionFind {

        private int[] rank;
        private int[] parent;

        public UnionFind(int count){
            rank = new int[count];
            parent = new int[count];

            for(int i = 0 ; i < count ; i ++){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        private int find(int p){
            while(p != parent[p]){
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;
        }

        public boolean isConnected(int p , int q){
            return find(p) == find(q);
        }

        public void unionElements(int p, int q){

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
    }

    private int d[][] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    private int m, n;

    public int numIslands(char[][] grid) {

        if(grid == null || grid.length == 0 || grid[0].length == 0)
            return 0;

        m = grid.length;
        n = grid[0].length;

        UnionFind uf = new UnionFind(m * n);
        for(int i = 0 ; i < m ; i ++)
            for(int j = 0; j < n ; j ++)
                if(grid[i][j] == '1')
                    for(int k = 0; k < 4; k ++){
                        int newX = i + d[k][0], newY = j + d[k][1];
                        if(inArea(newX, newY) && grid[newX][newY] == '1')
                            uf.unionElements(i * n + j, newX * n + newY);
                    }

        HashSet<Integer> islands = new HashSet<>();
        for(int i = 0 ; i < m ; i ++)
            for(int j = 0; j < n ; j ++)
                if(grid[i][j] == '1')
                    islands.add(uf.find(i * n + j));
        return islands.size();
    }

    private boolean inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    public static void main(String[] args) {

        char grid1[][] = {
                {'1','1','1','1','0'},
                {'1','1','0','1','0'},
                {'1','1','0','0','0'},
                {'0','0','0','0','0'}
        };
        System.out.println((new Solution3()).numIslands(grid1));
        // 1

        // ---

        char grid2[][] = {
                {'1','1','0','0','0'},
                {'1','1','0','0','0'},
                {'0','0','1','0','0'},
                {'0','0','0','1','1'}
        };
        System.out.println((new Solution3()).numIslands(grid2));
        // 3
    }
}
