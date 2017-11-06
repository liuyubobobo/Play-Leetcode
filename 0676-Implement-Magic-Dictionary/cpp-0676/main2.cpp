/// Source : https://leetcode.com/problems/implement-magic-dictionary/description/
/// Author : liuyubobobo
/// Time   : 2017-11-05

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/// Hash Set + Brute Force
/// Generate all possible answer in the set
///
/// Time Complexity: buildDict: O(len(dict)*w) where w is the avarage length of words in dict
///                  search: O(len(search_word))
/// Space Complexity: O(len(dict)*w*25)
class MagicDictionary {

private:
    unordered_set<string> records;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        records.clear();
    }

    /** Build a dictionary through a list of words */
    void buildDict(const vector<string>& dict) {

        for(string word: dict){
            for(int i = 0 ; i < word.size() ; i ++)
                for(int j = 0 ; j < 26 ; j ++){
                    char c = 'a' + j;
                    if(c != word[i])
                        records.insert(word.substr(0, i) + c +
                                       word.substr(i+1, word.size() - i - 1));
                }
        }

//        printRecords();
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(const string& word) {

        return records.find(word) != records.end();
    }

private:
    void printRecords(){
        cout << "RECORDS :" << endl;
        for(string e: records)
            cout << e << endl;
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