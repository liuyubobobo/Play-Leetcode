/// Source : https://leetcode.com/problems/encrypt-and-decrypt-strings/
/// Author : liuyubobobo
/// Time   : 2022-04-02

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Trie
/// Time Complexity: init: O(|keys| + |values| + character_number_in_dictionary)
///                  encrypt: O(|word1|)
///                  decrypt: O(min(|word2|^26, all_nodes_in_trie))
/// Space Compelxity: O(|keys| + |values| + character_number_in_dictionary)
class Encrypter {

private:
    class Node{

    public:
        vector<Node*> next;
        bool is_word;

        Node() : next(26, nullptr), is_word(false) {};
    };

    vector<int> char2index;
    vector<char> index2char;
    vector<string> index2values;
    map<string, vector<int>> len2s2indexes;
    Node* root;

public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) :
        index2char(keys), char2index(256, -1),
        index2values(values), root(new Node()){

        for(int i = 0; i < keys.size(); i ++)
            char2index[keys[i]] = i;

        for(int i = 0; i < values.size(); i ++)
            len2s2indexes[values[i]].push_back(i);

        for(const string& s: dictionary)
            insert(s);
    }

    string encrypt(string word1) {

        string res = "";
        for(char c: word1)
            res += index2values[char2index[c]];
        return res;
    }

    int decrypt(string word2) {
        return dfs(word2, 0, root);
    }

private:
    int dfs(const string& s, int index, Node* node){

        if(index == s.size()) return node->is_word;

        string len2s = s.substr(index, 2);
        vector<int>& v = len2s2indexes[len2s];

        int res = 0;
        for(int i: v)
            if(i < index2char.size() && node->next[index2char[i] - 'a'])
                res += dfs(s, index + 2, node->next[index2char[i] - 'a']);
        return res;
    }

    void insert(const string& word) {

        Node* cur = root;
        for(char c: word){
            if(cur->next[c - 'a'] == nullptr)
                cur->next[c - 'a'] = new Node();
            cur = cur->next[c - 'a'];
        }

        cur->is_word = true;
    }
};


int main() {

    return 0;
}
