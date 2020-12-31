/// Source : https://leetcode.com/problems/replace-words/description/
/// Author : liuyubobobo
/// Time   : 2017-11-10

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


/// Trie
/// Time Complexity: O(len(words) * O(w))
/// Space Complexity: O(len(words) * O(w))
class Trie {

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

    /** Inserts a word into the trie. */
    void insert(const string& word){

        int treeID = 0;
        for(char c: word){
            if(trie[treeID].next.find(c) == trie[treeID].next.end()){
                trie[treeID].next[c] = trie.size();
                trie.push_back(Node());
            }

            treeID = trie[treeID].next[c];
        }

        trie[treeID].end = true;
    }

    string getRoot(const string& word){

        int treeID = 0;
        string root = "";
        for(char c: word){
            if(trie[treeID].end)
                return root;

            if(trie[treeID].next.find(c) == trie[treeID].next.end())
                return "";

            root += c;
            treeID = trie[treeID].next[c];
        }
        return "";
    }

};

class Solution {
private:
    Trie trie;

public:
    string replaceWords(vector<string>& dict, string sentence) {

        for(string root: dict)
            trie.insert(root);

        vector<string> words = split(sentence, ' ');
//        for(string word: words)
//            cout << word << " ";
//        cout << endl;

        vector<string> res;
        for(string word: words){
            string root = trie.getRoot(word);
            res.push_back(root == "" ? word : root);
        }

        return join(res, ' ');
    }

private:
    vector<string> split(const string& s, char delimiter){

        vector<string> res;
        size_t i = 0;
        while(i < s.size()){
            size_t pos = s.find(delimiter, i);
            if(pos == string::npos){
                res.push_back(s.substr(i));
                break;
            }
            else{
                res.push_back(s.substr(i, pos-i));
                i = pos + 1;
            }
        }
        return res;
    }

    string join(const vector<string>& vec, char delimiter){

        if(vec.size() == 0)
            return "";

        string ret = vec[0];
        for(int i = 1 ; i < vec.size() ; i ++)
            ret += (delimiter + vec[i]);
        return ret;
    }
};

int main() {

    vector<string> dict;
    dict.push_back("cat");
    dict.push_back("bat");
    dict.push_back("rat");

    string sentence = "the cattle was rattled by the battery";

    cout << Solution().replaceWords(dict, sentence) << endl;

    return 0;
}