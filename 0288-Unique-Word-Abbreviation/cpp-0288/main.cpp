/// Source : https://leetcode.com/problems/unique-word-abbreviation/
/// Author : liuyubobobo
/// Time   : 2018-08-13

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cassert>
#include <stdexcept>

using namespace std;

/// Brute Force
/// Iterate all words in dictionary to see isUnique
/// Time Complexity: init : O(n)
///                         isUnique : O(n)
/// Space Complexity: O(n)
class ValidWordAbbr {

private:
    unordered_set<string> words;

public:
    ValidWordAbbr(vector<string> dictionary):
            words(dictionary.begin(), dictionary.end()) {}

    bool isUnique(string word) {

        for(const string& e: words){
            if(e == word)
                continue;

            int l = e.size();
            if(l == word.size() && e[0] == word[0] && e[l - 1] == word[l - 1])
                return false;
        }
        return true;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    vector<string> dictionary;
    dictionary.push_back("deer");
    dictionary.push_back("door");
    dictionary.push_back("cake");
    dictionary.push_back("card");
    dictionary.push_back("hello");

    ValidWordAbbr vwa(dictionary);

    print_bool(vwa.isUnique("dear"));
    print_bool(vwa.isUnique("cart"));
    print_bool(vwa.isUnique("cane"));
    print_bool(vwa.isUnique("make"));
    print_bool(vwa.isUnique("hello"));

    return 0;
}