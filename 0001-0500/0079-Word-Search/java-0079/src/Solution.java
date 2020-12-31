/// Source : https://leetcode.com/problems/word-search/description/
/// Author : liuyubobobo
/// Time   : 2017-10-14

// Backtrack
// Time Complexity: O(m*n*m*n)
// Space Complexity: O(m*n)
public class Solution {

    private int d[][] = {{-1,0},{0,1},{1,0},{0,-1}};
    private int m,n;
    private boolean[][] visited;

    public boolean exist(char[][] board, String word) {

        if(board == null || word == null)
            throw new IllegalArgumentException("board or word can not be null!");

        m = board.length;
        assert( m > 0 );
        n = board[0].length;

        visited = new boolean[m][n];
        for( int i = 0 ; i < m ; i ++ )
            for( int j = 0 ; j < n ; j ++ )
                if( searchWord( board, word, 0 , i, j) )
                    return true;

        return false;
    }

    private boolean inArea( int x , int y ){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // start from board[startx][starty], find word[index...word.size())
    private boolean searchWord( char[][] board, String word, int index,
                     int startx, int starty ){

        //assert( inArea(startx,starty) );
        if( index == word.length() - 1 )
            return board[startx][starty] == word.charAt(index);

        if( board[startx][starty] == word.charAt(index) ){
            visited[startx][starty] = true;
            for( int i = 0 ; i < 4 ; i ++ ){
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                if( inArea(newx, newy) && !visited[newx][newy] &&
                        searchWord( board , word , index + 1 , newx , newy ) )
                    return true;
            }
            visited[startx][starty] = false;
        }
        return false;
    }

    public static void main(String args[]){

        char[][] b1 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

        String words[] = {"ABCCED" , "SEE" , "ABCB" };
        for( int i = 0 ; i < words.length ; i ++ )
            if( (new Solution()).exist(b1, words[i]))
                System.out.println("found " + words[i]);
            else
                System.out.println("can not found " + words[i]);

        // ---

        char[][] b2 = {{'A'}};
        if( (new Solution()).exist(b2,"AB"))
            System.out.println("found AB");
        else
            System.out.println("can not found AB");
    }
}
