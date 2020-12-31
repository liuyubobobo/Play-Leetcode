/// Source : https://leetcode.com/problems/stream-of-characters/
/// Author : liuyubobobo
/// Time   : 2019-04-20

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Trie
/// Time Complexity: init: O(n * |word|)
///                  query: O(max length of words)
/// Space Complexity: O(n * |word| + |q|)
class Trie {

private:
    struct Node{
        unordered_map<char, int> next;
        bool end = false;
    };
    vector<Node> trie;

public:
    Trie(){
        trie.clear();
        trie.push_back(Node());
    }
    
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

    bool search(const string& q){

        int treeID = 0;
        for(int i = q.size() - 1; i >= 0; i --){

            if(trie[treeID].end) return true;

            char c = q[i];
            if(!trie[treeID].next.count(c))
                return false;

            treeID = trie[treeID].next[c];
        }
        return trie[treeID].end;
    }
};

class StreamChecker {

private:
    Trie trie;
    string q = "";

public:
    StreamChecker(vector<string>& words){

        for(string& word: words){
            reverse(word.begin(), word.end());
            trie.insert(word);
        }
    }

    bool query(char letter) {

        q += letter;
        return trie.search(q);
    }
};


int main() {

    return 0;
}