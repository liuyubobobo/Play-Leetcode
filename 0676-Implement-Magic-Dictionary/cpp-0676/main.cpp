/// Source : https://leetcode.com/problems/implement-magic-dictionary/description/
/// Author : liuyubobobo
/// Time   : 2017-11-05

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/// Hash Map + Bucket-By-Length
/// Time Complexity: buildDict: O(len(dict)*w) where w is the avarage length of words in dict
///                  search: O(len(dict)*len(search_word))
/// Space Complexity: O(len(dict)*w)
class MagicDictionary {

private:
    unordered_map<int, vector<string>> records;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        records.clear();
    }

    /** Build a dictionary through a list of words */
    void buildDict(const vector<string>& dict) {

        for(string word: dict){
            if(records.find(word.size()) == records.end())
                records[word.size()] = vector<string>();

            records[word.size()].push_back(word);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(const string& word) {

        if(records.find(word.size()) == records.end())
            return false;

        for(string aWord: records[word.size()])
            if(dis(aWord, word) == 1)
                return true;

        return false;
    }

private:
    int dis(const string& a, const string& b){
        int res = 0;
        for(int i = 0 ; i < a.size() ; i ++)
            if(a[i] != b[i])
                res ++;
        return res;
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