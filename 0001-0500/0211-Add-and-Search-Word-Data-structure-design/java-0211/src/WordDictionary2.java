/// Source : https://leetcode.com/problems/add-and-search-word-data-structure-design/
/// Author : liuyubobobo
/// Time   : 2022-11-13

import java.util.*;

/// Trie + Non-Recursive DFS
/// Time Complexity: addWord: O(len(word))
///                  search:  O(size(trie))
/// Space Complexity: O(sum(len(wi))) where wi is the length of the ith word
public class WordDictionary2 {

    private class Node{

        public boolean isWord = false;
        public int index;
        public Node next[];

        public Node(int index){
            this.index = index;
            next = new Node[26];
        }
    }

    private Node root;

    /** Initialize your data structure here. */
    public WordDictionary2() {
        root = new Node(0);
    }

    /** Adds a word into the data structure. */
    public void addWord(String word) {

        Node cur = root;
        for(int i = 0 ; i < word.length() ; i ++){
            char c = word.charAt(i);
            if(cur.next[c - 'a'] == null)
                cur.next[c - 'a'] = new Node(i + 1);
            cur = cur.next[c - 'a'];
        }
        cur.isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {

        Deque<Node> nodeStack = new LinkedList<>();

        nodeStack.push(root);
        while(!nodeStack.isEmpty()){
            Node node = nodeStack.poll();
            if(node.index == word.length()){
                if(node.isWord) return true;
                continue;
            }

            char c = word.charAt(node.index);
            if(c != '.'){
                if(node.next[c - 'a'] != null)
                    nodeStack.push(node.next[c - 'a']);
            }
            else{
                for(char nextChar = 0; nextChar < 26; nextChar ++){
                    if(node.next[nextChar] != null)
                        nodeStack.push(node.next[nextChar]);
                }
            }
        }
        return false;
    }
}