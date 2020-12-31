/// Source : https://leetcode.com/problems/design-search-autocomplete-system/
/// Author : liuyubobobo
/// Time   : 2019-07-30

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/// Trie
/// Time Complexity: init: O(total_letters)
///                  input: O(total_letters_in_trie + nlogn)
/// Space Complexity: O(total_letters_in_trie + num_of_input)
class Trie {

private:
    struct Node{
        unordered_map<char, Node*> next;
        int freq = 0;
    };
    Node* root = new Node;

public:
    Trie(){}

    void insert(const string& word, int f){

        Node* cur = root;
        for(char c: word){
            if(cur->next.find(c) == cur->next.end()){
                cur->next[c] = new Node();
            }

            cur = cur->next[c];
        }
        cur->freq += f;
    }

    vector<pair<int, string>> startsWith(const string& prefix) {

        Node* cur = root;
        for(char c: prefix){
            if(cur->next.find(c) == cur->next.end())
                return {};
            cur = cur->next[c];
        }

        vector<pair<int, string>> res;
        dfs(cur, prefix, res);
        return res;
    }

private:
    void dfs(Node* cur, const string& s, vector<pair<int, string>>& res){

        if(cur->freq)
            res.push_back(make_pair(cur->freq, s));

        for(const pair<char, Node*>& p: cur->next)
            dfs(p.second, s + p.first, res);
    }
};


class AutocompleteSystem {

    Trie trie;
    string cur = "";

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {

        for(int i = 0; i < sentences.size(); i ++)
            trie.insert(sentences[i], times[i]);
    }

    vector<string> input(char c) {

        if(c == '#'){
            trie.insert(cur, 1);
            cur = "";
            return {};
        }

        cur += c;
        vector<pair<int, string>> candidates = trie.startsWith(cur);
        sort(candidates.begin(), candidates.end(),
             [](const pair<int, string>& p1, const pair<int, string>& p2){
                 if(p1.first != p2.first) return p1.first > p2.first;
                 return p1.second < p2.second;
             });

        vector<string> res;
        for(int i = 0; i < min((int)candidates.size(), 3); i ++)
            res.push_back(candidates[i].second);
        return res;
    }
};


void print_vec(const vector<string>& vec){
    for(const string& e: vec) cout << e << endl;
}

int main() {

    vector<string> sentences = {"i love you","island","iroman","i love leetcode"};
    vector<int> times = {5, 3, 2, 2};
    AutocompleteSystem sys(sentences, times);
    print_vec(sys.input('i'));
    print_vec(sys.input(' '));
    print_vec(sys.input('a'));

    return 0;
}