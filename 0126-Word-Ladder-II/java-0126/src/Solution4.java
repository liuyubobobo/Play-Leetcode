/// Source : https://leetcode.com/problems/word-ladder/description/
/// Author : liuyubobobo
/// Time   : 2018-03-27

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.LinkedList;
import java.util.HashMap;

/// Bi-directional BFS
/// No need to calculate all pairs similarity
/// Time Complexity: O(n*n)
/// Space Complexity: O(n)
public class Solution4 {

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {

        if(!wordList.contains(endWord))
            return 0;

        // bi-derectional-bfs
        LinkedList<String> qStart = new LinkedList<>();
        LinkedList<String> qEnd = new LinkedList<>();

        HashMap<String, Integer> stepStart = new HashMap<>();
        HashMap<String, Integer> stepEnd = new HashMap<>();

        qStart.addLast(beginWord);
        stepStart.put(beginWord, 1);

        qEnd.addLast(endWord);
        stepEnd.put(endWord, 1);

        while(!qStart.isEmpty() && !qEnd.isEmpty()){

            String curStartWord = qStart.removeFirst();
            String curEndWord = qEnd.removeFirst();
            for(String word: wordList){
                if(!stepStart.containsKey(word) && similar(word, curStartWord)){
                    stepStart.put(word, stepStart.get(curStartWord) + 1);
                    qStart.addLast(word);
                }

                if(!stepEnd.containsKey(word) && similar(word, curEndWord)){
                    stepEnd.put(word, stepEnd.get(curEndWord) + 1);
                    qEnd.addLast(word);
                }
            }

            // check intersection
            int res = Integer.MAX_VALUE;
            for(String word: wordList)
                if(stepStart.containsKey(word) && stepEnd.containsKey(word))
                    res = Integer.min(res,
                            stepStart.get(word) + stepEnd.get(word) - 1);

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
