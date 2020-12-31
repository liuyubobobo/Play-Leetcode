/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2018-06-01

import java.util.List;
import java.util.ArrayList;

/// Floodfill
/// Time Complexity: O(m*n)
/// Space Complexity: O(m*n)
class Solution {

    private int n, m;
    private boolean[][] pacific, atlantic;
    private int[][] d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public List<int[]> pacificAtlantic(int[][] matrix) {

        ArrayList<int[]> res = new ArrayList<>();

        n = matrix.length;
        if(n == 0)
            return res;
        m = matrix[0].length;

        pacific = new boolean[n][m];
        atlantic = new boolean[n][m];

        for(int i = 0 ; i < n ; i ++){
            dfs(matrix, pacific, i, 0);
            dfs(matrix, atlantic, i, m - 1);
        }

        for(int j = 0 ; j < m ; j ++){
            dfs(matrix, pacific, 0, j);
            dfs(matrix, atlantic, n - 1, j);
        }

        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                if(pacific[i][j] && atlantic[i][j])
                    res.add(new int[]{i, j});
        return res;
    }

    private void dfs(int[][] matrix, boolean[][] visited, int x, int y){

        visited[x][y] = true;
        for(int i = 0 ; i < 4 ; i ++){
            int newX = x + d[i][0];
            int newY = y + d[i][1];
            if(inArea(newX, newY) && !visited[newX][newY] && matrix[newX][newY] >= matrix[x][y])
                dfs(matrix, visited, newX, newY);
        }
    }

    private boolean inArea(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    public static void printList(List<int[]> list){
        for(int[] e: list)
            System.out.print("[ " + e[0] + " , " + e[1] + " ] ");
        System.out.println();
    }

    public static void main(String[] args){

        int[][] matrix = new int[][]{
                {1,   2,   2,   3,  5},
                {3,   2,   3,   4,  4},
                {2,   4,   5,   3,  1},
                {6,   7,   1,   4,  5},
                {5,   1,   1,   2,  4}
        };
        List<int[]> res = (new Solution()).pacificAtlantic(matrix);
        printList(res);
    }
}
