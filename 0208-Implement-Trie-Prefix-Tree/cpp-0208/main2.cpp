/// Source : https://leetcode.com/problems/implement-trie-prefix-tree/description/
/// Author : liuyubobobo
/// Time   : 2017-11-05

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/// Trie Non-Recursive version
class Trie{

private:
    struct Node{
        map<char, int> next;
        bool end = false;
    };
    vector<Node> trie;

public:
    Trie(){
        trie.clear();
        trie.push_back(Node());
    }

    /** Inserts a word into the trie. */
    void insert(const string& word){

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

    /** Returns if the word is in the trie. */
    bool search(const string& word){

        int treeID = 0;
        for(char c: word){
            if(trie[treeID].next.find(c) == trie[treeID].next.end())
                return false;

            treeID = trie[treeID].next[c];
        }
        return trie[treeID].end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) {

        int treeID = 0;
        for(char c: prefix){
            if(trie[treeID].next.find(c) == trie[treeID].next.end())
                return false;

            treeID = trie[treeID].next[c];
        }
        return true;
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    Trie trie1;
    trie1.insert("ab");
    printBool(trie1.search("a"));     // false
    printBool(trie1.startsWith("a")); // true;

    cout << endl;

    // ---

    Trie trie2;
    trie2.insert("a");
    printBool(trie2.search("a"));     // true
    printBool(trie2.startsWith("a")); // true;

    return 0;
}