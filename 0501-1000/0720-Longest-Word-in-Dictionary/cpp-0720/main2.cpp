/// Source : https://leetcode.com/problems/longest-word-in-dictionary/description/
/// Author : liuyubobobo
/// Time   : 2017-11-05

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

/// Trie + DFS
/// Time Complexity: O(sum(wi)) where wi is the length of the ith word
/// Space Complexity: O(sum(wi))
class Solution {

private:
    struct Node{
        map<char, int> next;
        bool end = false;
    };
    vector<Node> trie;

public:
    string longestWord(vector<string>& words) {

        build_trie(words);

        string res = "";
        dfs(0, "", res);
        return res;
    }

private:
    void build_trie(const vector<string>& words){

        trie.clear();
        trie.push_back(Node());
        for(string word: words)
            insert_word(0, word, 0);
    }

    void insert_word(int treeID, const string& word, int index){

        if(index == word.size()) {
            trie[treeID].end = true;
            return;
        }

        if(trie[treeID].next.find(word[index]) == trie[treeID].next.end()){
            trie[treeID].next[word[index]] = trie.size();
            trie.push_back(Node());
        }

        insert_word(trie[treeID].next[word[index]], word, index + 1);
    }

    void dfs(int treeID, const string& cur, string& res){

        if(cur.size() > res.size() || (cur.size() == res.size() && cur < res))
            res = cur;

        for(pair<char, int> next: trie[treeID].next)
            if(trie[next.second].end)
                dfs(next.second, cur + next.first, res);
    }
};

int main() {

    vector<string> words1;
    words1.push_back("w");
    words1.push_back("wo");
    words1.push_back("wor");
    words1.push_back("worl");
    words1.push_back("world");
    cout << Solution().longestWord(words1) << endl;
    // world

    // ---

    vector<string> words2;
    words2.push_back("a");
    words2.push_back("banana");
    words2.push_back("app");
    words2.push_back("appl");
    words2.push_back("ap");
    words2.push_back("apply");
    words2.push_back("apple");
    cout << Solution().longestWord(words2) << endl;
    // apple

    return 0;
}