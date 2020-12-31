/// Source : https://leetcode.com/problems/word-ladder/description/
/// Author : liuyubobobo
/// Time   : 2018-03-27

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.LinkedList;

/// Bi-directional BFS
/// Time Complexity: O(n*n)
/// Space Complexity: O(n)
public class Solution3 {

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


        // bi-derectional-bfs
        LinkedList<Integer> qStart = new LinkedList<>();
        LinkedList<Integer> qEnd = new LinkedList<>();

        int[] stepStart = new int[n];
        int[] stepEnd = new int[n];

        qStart.addLast(begin);
        stepStart[begin] = 1;

        qEnd.addLast(end);
        stepEnd[end] = 1;

        while(!qStart.isEmpty() && !qEnd.isEmpty()){

            int curStart = qStart.removeFirst();
            int curEnd = qEnd.removeFirst();

            for(int i = 0 ; i < n ; i ++) {
                if (stepStart[i] == 0 && g[curStart][i]) {
                    stepStart[i] = stepStart[curStart] + 1;
                    qStart.addLast(i);
                }
            }

            for(int i = 0 ; i < n ; i ++){
                if(stepEnd[i] == 0 && g[curEnd][i]){
                    stepEnd[i] = stepEnd[curEnd] + 1;
                    qEnd.addLast(i);
                }
            }

            // check intersection
            int res = Integer.MAX_VALUE;
            for(int i = 0 ; i < n ; i ++)
                if(stepStart[i] != 0 && stepEnd[i] != 0)
                    res = Integer.min(res, stepStart[i] + stepEnd[i] - 1);

            if(res != Integer.MAX_VALUE)
                return res;
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
