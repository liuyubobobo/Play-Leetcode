/// Source : https://leetcode.com/problems/add-and-search-word-data-structure-design/
/// Author : liuyubobobo
/// Time   : 2019-04-07

import java.util.HashMap;


/// Trie
/// Time Complexity: addWord: O(len(word))
///                  search:  O(size(trie))
/// Space Complexity: O(sum(len(wi))) where wi is the length of the ith word
class WordDictionary {

    private class Node{

        public HashMap<Character, Node> next = new HashMap<>();
        public boolean end = false;
    }

    private Node trie;

    /** Initialize your data structure here. */
    public WordDictionary() {
        trie = new Node();
    }

    /** Adds a word into the data structure. */
    public void addWord(String word) {

        Node cur = trie;
        for(int i = 0; i < word.length(); i ++){
            char c = word.charAt(i);
            if(cur.next.get(c) == null)
                cur.next.put(c, new Node());
            cur = cur.next.get(c);
        }

        cur.end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return search(trie, word, 0);
    }

    private boolean search(Node node, String word, int index){

        if(index == word.length())
            return node.end;

        char c = word.charAt(index);
        if(c != '.'){
            if(node.next.get(c) == null)
                return false;

            return search(node.next.get(c), word, index + 1);
        }
        else{
            for(char key: node.next.keySet())
                if(search(node.next.get(key), word, index + 1))
                    return true;

            return false;
        }
    }
}