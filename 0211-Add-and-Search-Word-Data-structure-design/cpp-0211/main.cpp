/// Source : https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
/// Author : liuyubobobo
/// Time   : 2017-11-10

#include <iostream>
#include <map>
#include <vector>

using namespace std;

/// Trie
/// Time Complexity: addWord: O(len(word))
///                  search:  O(size(trie))
/// Space Complexity: O(sum(len(wi))) where wi is the length of the ith word
class WordDictionary {

private:
    struct Node {
        map<char, int> next;
        bool end = false;
    };
    vector<Node> trie;

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trie.clear();
        trie.push_back(Node());
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        int treeID = 0;
        for(char c: word){
            if(trie[treeID].next.find(c) == trie[treeID].next.end()){
                trie[treeID].next[c] = trie.size();
                trie.push_back(Node());
            }

            treeID = trie[treeID].next[c];
        }

        trie[treeID].end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(0, word, 0);
    }

private:
    bool search(int treeID, const string &word, int index) {

        if (index == word.size())
            return trie[treeID].end;

        if(word[index] != '.'){
            if (trie[treeID].next.find(word[index]) == trie[treeID].next.end())
                return false;

            return search(trie[treeID].next[word[index]], word, index + 1);
        }
        else{
            for(pair<char, int> next: trie[treeID].next)
                if(search(next.second, word, index + 1))
                    return true;
            return false;
        }
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    WordDictionary obj;
    obj.addWord("bad");
    obj.addWord("mad");
    obj.addWord("dad");
    printBool(obj.search("pad")); // false
    printBool(obj.search("bad")); // true
    printBool(obj.search(".ad")); // true
    printBool(obj.search("b..")); // true

    return 0;
}