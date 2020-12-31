/// Source : https://leetcode.com/problems/implement-magic-dictionary/description/
/// Author : liuyubobobo
/// Time   : 2017-11-05

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/// Trie
///
/// Time Complexity: buildDict: O(len(dict)*w) where w is the avarage length of words in dict
///                  search: O(len(dict)*w)
/// Space Complexity: O(len(dict)*w)

class Trie{

private:
    struct Node{
        map<char, int> next;
        bool end = false;
    };
    vector<Node> trie;

public:
    Trie(){
        trie.clear();
        trie.push_back(Node());
    }

    void insert(const string& word){
        insert(0, word, 0);
    }

    bool search(const string& word){
        return search(0, word, 0, 1);
    }

private:
    void insert(int treeID, const string& word, int index){

        if(index == word.size()) {
            trie[treeID].end = true;
            return;
        }

        if(trie[treeID].next.find(word[index]) == trie[treeID].next.end()){
            trie[treeID].next[word[index]] = trie.size();
            trie.push_back(Node());
        }

        insert(trie[treeID].next[word[index]], word, index + 1);
    }

    bool search(int treeID, const string& word, int index, int left){

        if(index == word.size())
            return trie[treeID].end && left == 0;

        for(pair<char, int> next: trie[treeID].next)
            if(next.first == word[index]){
                if(search(next.second, word, index + 1, left))
                    return true;
            }
            else if(left > 0){
                if(search(next.second, word, index + 1, left-1))
                    return true;
            }

        return false;
    }
};

class MagicDictionary {

private:
    Trie trie;

public:
    /** Initialize your data structure here. */
    MagicDictionary() {}

    /** Build a dictionary through a list of words */
    void buildDict(const vector<string>& dict) {

        for(string word: dict)
            trie.insert(word);
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(const string& word) {

        return trie.search(word);
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    vector<string> dict1;
    dict1.push_back("hello");
    dict1.push_back("leetcode");

    MagicDictionary obj1;
    obj1.buildDict(dict1);
    printBool(obj1.search("hello"));     // false
    printBool(obj1.search("hhllo"));     // true
    printBool(obj1.search("hell"));      // false
    printBool(obj1.search("leetcoded")); // false

    cout << endl;

    // ---

    vector<string> dict2;
    dict2.push_back("hello");
    dict2.push_back("hallo");
    dict2.push_back("leetcode");

    MagicDictionary obj2;
    obj2.buildDict(dict2);
    printBool(obj2.search("hello"));     // true
    printBool(obj2.search("hhllo"));     // true
    printBool(obj2.search("hell"));      // false
    printBool(obj2.search("leetcoded")); // false

    return 0;
}