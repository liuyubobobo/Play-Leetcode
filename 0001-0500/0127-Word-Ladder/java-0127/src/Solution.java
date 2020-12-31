/// Source : https://leetcode.com/problems/word-ladder/description/
/// Author : liuyubobobo
/// Time   : 2018-03-27

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.LinkedList;

/// BFS
/// Time Complexity: O(n*n)
/// Space Complexity: O(n)
public class Solution {

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {

        int end = wordList.indexOf(endWord);
        if(end == -1)
            return 0;

        if(!wordList.contains(beginWord))
            wordList.add(beginWord);
        int begin = wordList.indexOf(beginWord);

        int n = wordList.size();
        boolean[][] g = new boolean[n][n];
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < i ; j ++)
                g[j][i] = g[i][j] = similar(wordList.get(i), wordList.get(j));

        // bfs
        LinkedList<Integer> q = new LinkedList<>();
        int[] step = new int[n];

        q.addLast(begin);
        step[begin] = 1;
        while(!q.isEmpty()){

            int cur = q.removeFirst();

            for(int i = 0 ; i < n ; i ++)
                if(step[i] == 0 && g[cur][i]){
                    if(i == end)
                        return step[cur] + 1;
                    step[i] = step[cur] + 1;
                    q.addLast(i);
                }
        }

        return 0;
    }

    private boolean similar(String word1, String word2){

        if(word1.length() != word2.length() || word1.equals(word2))
            throw new IllegalArgumentException();

        int diff = 0;
        for(int i = 0 ; i < word1.length() ; i ++)
            if(word1.charAt(i) != word2.charAt(i)){
                diff ++;
                if(diff > 1)
                    return false;
            }
        return true;
    }

    public static void main(String[] args) {

        ArrayList<String> wordList1 = new ArrayList<String>(
                Arrays.asList("hot","dot","dog","lot","log","cog"));
        String beginWord1 = "hit";
        String endWord1 = "cog";
        System.out.println((new Solution()).ladderLength(beginWord1, endWord1, wordList1));

        // 5

        // ---

        ArrayList<String> wordList2 = new ArrayList<String>(
                Arrays.asList("a","b","c"));
        String beginWord2 = "a";
        String endWord2 = "c";
        System.out.println((new Solution()).ladderLength(beginWord2, endWord2, wordList2));
        // 2
    }
}
