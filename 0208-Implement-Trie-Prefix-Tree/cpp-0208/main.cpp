/// Source : https://leetcode.com/problems/implement-trie-prefix-tree/description/
/// Author : liuyubobobo
/// Time   : 2017-11-05

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/// Trie Recursive version
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
        insert(0, word, 0);
    }

    /** Returns if the word is in the trie. */
    bool search(const string& word){
        return search(0, word, 0);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) {
        return startsWith(0, prefix, 0);
    }

private:
    void insert(int treeID, const string& word, int index){

        if(index == word.size()) {
            trie[treeID].end = true;
            return;
        }

        if(trie[treeID].next.find(word[index]) == trie[treeID].next.end()){
            trie[treeID].next[word[index]] = trie.size();
            trie.push_back(Node());
        }

        insert(trie[treeID].next[word[index]], word, index + 1);
    }

    bool search(int treeID, const string& word, int index){

        if(index == word.size())
            return trie[treeID].end;

        if(trie[treeID].next.find(word[index]) == trie[treeID].next.end())
            return false;

        return search(trie[treeID].next[word[index]], word, index + 1);
    }

    bool startsWith(int treeID, const string& prefix, int index){

        if(index == prefix.size())
            return true;

        if(trie[treeID].next.find(prefix[index]) == trie[treeID].next.end())
            return false;

        return startsWith(trie[treeID].next[prefix[index]], prefix, index + 1);
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