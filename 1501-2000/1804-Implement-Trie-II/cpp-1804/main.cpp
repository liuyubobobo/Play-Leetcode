/// Source : https://leetcode.com/problems/implement-trie-ii-prefix-tree/
/// Author : liuyubobobo
/// Time   : 2021-06-18

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Trie
/// Time Complexity: O(|s|)
/// Space Complexity: O(total_characters)
class Trie {

private:
    class Node{

    public:
        vector<Node*> next;
        int word_cnt, sz;

        Node() : next(26, nullptr), word_cnt(0), sz(0) {};
    };

    Node* root;

public:
    Trie() : root(new Node()) {}

    void insert(string word) {

        Node* cur = root;
        stack<Node*> stack;
        stack.push(root);
        for(char c: word){
            if(cur->next[c - 'a'] == nullptr)
                cur->next[c - 'a'] = new Node();
            cur = cur->next[c - 'a'];
            stack.push(cur);
        }

        cur->word_cnt ++;

        while(!stack.empty()){
            Node* node = stack.top();
            stack.pop();
            node->sz ++;
        }
    }

    int countWordsEqualTo(string word) {

        Node* cur = root;
        for(char c: word){
            if(cur->next[c - 'a'] == nullptr)
                return 0;
            cur = cur->next[c - 'a'];
        }
        return cur->word_cnt;
    }

    int countWordsStartingWith(string prefix) {

        Node* cur = root;
        for(char c: prefix){
            if(cur->next[c - 'a'] == nullptr)
                return 0;
            cur = cur->next[c - 'a'];
        }
        return cur->sz;
    }

    void erase(string word) {

        Node* cur = root;
        stack<Node*> stack;
        stack.push(root);
        for(char c: word){
            assert(cur->next[c - 'a']);
            cur = cur->next[c - 'a'];
            stack.push(cur);
        }

        assert(cur->word_cnt);

        cur->word_cnt --;

        while(!stack.empty()){
            Node* node = stack.top();
            stack.pop();
            node->sz --;
        }
    }
};


int main() {

    return 0;
}
