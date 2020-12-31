/// Source : https://leetcode.com/problems/map-sum-pairs/description/
/// Author : liuyubobobo
/// Time   : 2017-11-05

#include <iostream>
#include <map>
#include <vector>

using namespace std;

/// Trie
/// Time Complexity: insert: O(len(prefix))
///                  sum: O(sum(len(wi)))
/// Space Complexity: O(sum(len(wi))) where wi is the length of the ith word.

class Trie{

private:
    struct Node{
        map<char, int> next;
        int val = 0;
    };
    vector<Node> trie;

public:
    Trie(){
        trie.clear();
        trie.push_back(Node());
    }

    void insert(const string& word, int val){
        insert(0, word, 0, val);
    }

    int sum(const string& prefix){
        int treeID = findTreeID(0, prefix, 0);
        if(treeID == -1)
            return 0;
        return dfs(treeID);
    }

private:
    void insert(int treeID, const string& word, int index, int val){

        if(index == word.size()) {
            trie[treeID].val = val;
            return;
        }

        if(trie[treeID].next.find(word[index]) == trie[treeID].next.end()){
            trie[treeID].next[word[index]] = trie.size();
            trie.push_back(Node());
        }

        insert(trie[treeID].next[word[index]], word, index + 1, val);
    }

    int findTreeID(int treeID, const string& word, int index){

        if(index == word.size())
            return treeID;

        if(trie[treeID].next.find(word[index]) == trie[treeID].next.end())
            return -1;

        return findTreeID(trie[treeID].next[word[index]], word, index + 1);
    }

    int dfs(int treeID){

        int res = trie[treeID].val;
        for(pair<char, int> next: trie[treeID].next)
            res += dfs(next.second);
        return res;
    }
};

class MapSum {

private:
    Trie trie;

public:

    void insert(string key, int val) {
        trie.insert(key, val);
    }

    int sum(string prefix) {
        return trie.sum(prefix);
    }
};

int main() {

    MapSum obj;
    obj.insert("apple", 3);
    cout << obj.sum("ap") << endl; // 3
    obj.insert("app", 2);
    cout << obj.sum("ap") << endl; // 5

    return 0;
}