/// Source : https://leetcode.com/problems/longest-word-in-dictionary/description/
/// Author : liuyubobobo
/// Time   : 2017-11-04

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

/// Hash Table + Brute Force
/// Time Complexity: O(sum(wi^2)) where wi is the length of the ith word
/// Space Complexity: O(sum(wi))
class Solution {

public:
    string longestWord(vector<string>& words) {

        unordered_set<string> unique_words;
        for(string word: words)
            unique_words.insert(word);

        sort(words.begin(), words.end(), cmp);
//        printWords(words);
        for(string word: words)
            if(contain(unique_words, word))
                return word;

        return "";
    }

private:
    static bool cmp(const string &sa, const string& sb){
        if(sa.size() != sb.size())
            return sa.size() > sb.size();
        return sa < sb;
    }

    void printWords(const vector<string>& words){
        for(string word: words)
            cout << word << " ";
        cout << endl;
    }

    bool contain(const unordered_set<string>& words, const string& word){
        for(int len = word.size() - 1 ; len >= 1 ; len --)
            if(words.find(word.substr(0, len)) == words.end())
                return false;
        return true;
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