/// Source : https://leetcode.com/problems/implement-magic-dictionary/description/
/// Author : liuyubobobo
/// Time   : 2017-11-05

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/// Hash Map + Store-All-Patterns
///
/// Time Complexity: buildDict: O(len(dict)*w) where w is the avarage length of words in dict
///                  search: O(len(search_word)^2)
/// Space Complexity: O(len(dict)*w)
class MagicDictionary {

private:
    unordered_set<string> unique_words;
    unordered_map<string, int> records;

public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        unique_words.clear();
        records.clear();
    }

    /** Build a dictionary through a list of words */
    void buildDict(const vector<string>& dict) {

        for(string word: dict){
            unique_words.insert(word);
            for(int i = 0 ; i < word.size() ; i ++){
                string pattern = word.substr(0, i) + "*" +
                                 word.substr(i+1, word.size() - i - 1);
                if(records.find(pattern) == records.end())
                    records[pattern] = 1;
                else
                    records[pattern] += 1;
            }
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(const string& word) {

        bool inDict = (unique_words.find(word) != unique_words.end());
        for(int i = 0 ; i < word.size() ; i ++){
            string pattern = word.substr(0, i) + "*" +
                             word.substr(i+1, word.size() - i - 1);

            if(inDict && records[pattern] > 1)
                return true;

            if(!inDict && records[pattern] > 0)
                return true;
        }

        return false;
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