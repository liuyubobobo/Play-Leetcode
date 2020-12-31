/// Source : https://leetcode.com/problems/map-sum-pairs/description/
/// Author : liuyubobobo
/// Time   : 2017-11-05

#include <iostream>
#include <map>
#include <vector>

using namespace std;

/// Trie
/// Update key value when key already in the trie
/// Time Complexity: insert: O(len(prefix))
///                  sum: O(len(prefix))
/// Space Complexity: O(sum(len(wi))) where wi is the length of the ith word.

class Trie{

private:
    struct Node{
        map<char, int> next;
        int val = 0;
        bool end = false;
    };
    vector<Node> trie;

public:
    Trie(){
        trie.clear();
        trie.push_back(Node());
    }

    void insert(const string& word, int val){
        insert(0, word, 0, val);
//        cout << "After insert " << word << ", trie is:" << endl;
//        print();
    }

    int sum(const string& prefix){
        int treeID = findTreeID(0, prefix, 0);
        if(treeID == -1)
            return 0;
        return trie[treeID].val;
    }

private:
    int insert(int treeID, const string& word, int index, int val){

        if(index == word.size()) {

            if(trie[treeID].end){
                int change = val - trie[treeID].val;
                trie[treeID].val = val;
                return change;
            }
            else{
                trie[treeID].end = true;
                trie[treeID].val += val;
                return val;
            }
        }

        if(trie[treeID].next.find(word[index]) == trie[treeID].next.end()){
            trie[treeID].next[word[index]] = trie.size();
            trie.push_back(Node());
        }

        int change = insert(trie[treeID].next[word[index]], word, index + 1, val);
        trie[treeID].val += change;

        return change;
    }

    int findTreeID(int treeID, const string& word, int index){

        if(index == word.size())
            return treeID;

        if(trie[treeID].next.find(word[index]) == trie[treeID].next.end())
            return -1;

        return findTreeID(trie[treeID].next[word[index]], word, index + 1);
    }

    void print(){
        for(Node node: trie)
            cout << node.val << " ";
        cout << endl;
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