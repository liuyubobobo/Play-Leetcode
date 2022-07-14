/// Source : https://leetcode.com/problems/prefix-and-suffix-search/
/// Author : liuyubobobo
/// Time   : 2022-07-14

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


/// Suffix + Prefix
/// Time Complexity: init: O(sum_of_characters)
///                  query: O(|prefix| + |suffix|)
/// Space Complexity: O(sum_of_characters)
class Trie {

private:
    struct Node{
        map<char, Node*> next;
        int index = -1;
    };
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(const string& word, int index){

        Node* cur = root;
        bool flag = false;
        for(char c: word){
            if(cur->next.find(c) == cur->next.end()){
                cur->next[c] = new Node();
            }
            cur = cur->next[c];

            if(c == '#') flag = true;
            if(flag) cur->index = index;
        }
    }

    int get(const string& s) {

        Node* cur = root;
        for(char c: s){
            if(cur->next.find(c) == cur->next.end())
                return -1;

            cur = cur->next[c];
        }
        return cur->index;
    }
};

class WordFilter {

private:
    Trie trie;

public:
    WordFilter(vector<string> words) {
        for(int i = 0 ; i < words.size() ; i ++){
            string s = words[i];
            for(int j = s.size() - 1; j >= 0; j --){
                string suf = s.substr(j);
                trie.insert(suf + "#" + s, i);
            }
        }

    }

    int f(string prefix, string suffix) {
        return trie.get(suffix + "#" + prefix);
    }
};


int main() {

    return 0;
}
