/// Source : https://leetcode.com/problems/number-of-islands/description/
/// Author : liuyubobobo
/// Time   : 2018-08-29

import java.util.Stack;
import javafx.util.Pair;

/// Floodfill - DFS
/// Non-recursion implementation
///
/// Time Complexity: O(n*m)
/// Space Complexity: O(n*m)
class Solution2 {

    private int d[][] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    private int m, n;
    private boolean visited[][];

    public int numIslands(char[][] grid) {

        if(grid == null || grid.length == 0 || grid[0].length == 0)
            return 0;

        m = grid.length;
        n = grid[0].length;

        visited = new boolean[m][n];

        int res = 0;
        for(int i = 0 ; i < m ; i ++)
            for(int j = 0 ; j < n ; j ++)
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, i, j);
                    res ++;
                }

        return res;
    }

    private void dfs(char[][] grid, int x, int y){

        Stack<Pair<Integer, Integer>> q = new Stack<>();
        q.push(new Pair(x, y));
        visited[x][y] = true;
        while(!q.isEmpty()){
            Pair<Integer, Integer> cur = q.pop();
            int curx = cur.getKey();
            int cury = cur.getValue();

            for(int i = 0; i < 4; i ++){
                int newX = curx + d[i][0];
                int newY = cury + d[i][1];
                if(inArea(newX, newY) && !visited[newX][newY] && grid[newX][newY] == '1'){
                    q.push(new Pair(newX, newY));
                    visited[newX][newY] = true;
                }
            }
        }
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
        System.out.println((new Solution2()).numIslands(grid1));
        // 1

        // ---

        char grid2[][] = {
                {'1','1','0','0','0'},
                {'1','1','0','0','0'},
                {'0','0','1','0','0'},
                {'0','0','0','1','1'}
        };
        System.out.println((new Solution2()).numIslands(grid2));
        // 3
    }
}
