/// Source : https://leetcode.com/problems/add-and-search-word-data-structure-design/
/// Author : liuyubobobo
/// Time   : 2019-09-01

/// Trie + Recursive DFS
/// Time Complexity: addWord: O(len(word))
///                  search:  O(size(trie))
/// Space Complexity: O(sum(len(wi))) where wi is the length of the ith word
public class WordDictionary {

    private class Node{

        public boolean isWord;
        public Node next[];

        public Node(boolean isWord){
            this.isWord = isWord;
            next = new Node[26];
        }

        public Node(){
            this(false);
        }
    }

    private Node root;

    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new Node();
    }

    /** Adds a word into the data structure. */
    public void addWord(String word) {

        Node cur = root;
        for(int i = 0 ; i < word.length() ; i ++){
            char c = word.charAt(i);
            if(cur.next[c - 'a'] == null)
                cur.next[c - 'a'] = new Node();
            cur = cur.next[c - 'a'];
        }
        cur.isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return match(root, word, 0);
    }

    private boolean match(Node node, String word, int index){

        if(index == word.length())
            return node.isWord;

        char c = word.charAt(index);

        if(c != '.'){
            if(node.next[c - 'a'] == null)
                return false;
            return match(node.next[c - 'a'], word, index + 1);
        }
        else{
            for(char nextChar = 'a'; nextChar <= 'z'; nextChar ++)
                if(node.next[nextChar - 'a'] != null && match(node.next[nextChar - 'a'], word, index + 1))
                    return true;
            return false;
        }
    }
}