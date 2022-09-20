/// Source : https://leetcode.com/problems/sum-of-prefix-scores-of-strings/
/// Author : liuyubobobo
/// Time   : 2022-09-20

#include <iostream>
#include <vector>

using namespace std;


/// Using Trie
/// Time Complexity: O(all_characters int words)
/// Space Complexity: O(all_characters int words)
class Trie {

private:
    class Node{

    public:
        vector<Node*> next;
        int sz;

        Node() : next(26, nullptr), sz(0) {};
    };

    Node* root;

public:
    Trie() : root(new Node()) {}

    void insert(const string& word) {

        Node* cur = root;
        root->sz ++;
        for(char c: word){
            if(cur->next[c - 'a'] == nullptr)
                cur->next[c - 'a'] = new Node();
            cur = cur->next[c - 'a'];
            cur->sz ++;
        }
    }

    int query(const string& word) {

        Node* cur = root;
        int res = 0;
        for(char c: word){
            if(cur->next[c - 'a'] == nullptr)
                return res;
            cur = cur->next[c - 'a'];
            res += cur->sz;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {

        Trie trie;
        for(const string& word: words)
            trie.insert(word);

        vector<int> res;
        for(const string& word: words)
            res.push_back(trie.query(word));
        return res;
    }
};

int main() {

    return 0;
}
