/// Source : https://leetcode.com/problems/longest-word-with-all-prefixes/
/// Author : liuyubobobo
/// Time   : 2021-05-16

#include <iostream>
#include <vector>

using namespace std;


/// Trie
/// Time Complexity: O(all_letters)
/// Space Complexity: O(all_letters)
class Trie{

private:
    class Node{
    public:
        vector<Node*> next;
        bool is_end;
        Node() : next(26, nullptr), is_end(false){}
    };

    Node* root;

public:
    Trie(){
        root = new Node();
//        root->is_end = true;
    }

    void add(const string& s){

        Node* pre = root;
        for(char c: s){
            if(!pre->next[c - 'a'])
                pre->next[c - 'a'] = new Node();
            pre = pre->next[c - 'a'];
        }
        pre->is_end = true;
    }

    string query(){

        string res = "";
        dfs(root, "", res);
        return res;
    }

private:
    void dfs(const Node* node, const string& cur, string& res){

        if(cur.size() > res.size()) res = cur;
        else if(cur.size() == res.size()) res = min(res, cur);

        for(int i = 0; i < 26; i ++)
            if(node->next[i] && node->next[i]->is_end)
                dfs(node->next[i], cur + string(1, 'a' + i), res);
    }
};

class Solution {

public:
    string longestWord(vector<string>& words) {

        Trie trie;
        for(const string& word: words)
            trie.add(word);

        return trie.query();
    }
};


int main() {

    vector<string> words1 = {"k","ki","kir","kira", "kiran"};
    cout << Solution().longestWord(words1) << endl;
    // kiran

    return 0;
}
