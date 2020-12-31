/// Source : https://leetcode.com/problems/vowel-spellchecker/
/// Author : liuyubobobo
/// Time   : 2019-03-17

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/// Using HashSet and HashMap
/// Time Complexity: O(n + q)
/// Space Complexity: O(n)
class Solution {

private:
    const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {

        unordered_set<string> set;
        unordered_map<string, vector<string>> map1; // all_lower -> origin
        unordered_map<string, vector<string>> map2; // replace vowel -> origin
        for(const string& word: wordlist){
            set.insert(word);

            string lower_word = to_lower(word);
            map1[lower_word].push_back(word);

            string novowel_word = replace_vowel(word);
            map2[novowel_word].push_back(word);
        }

        vector<string> res;
        for(const string& query: queries){

            bool ok = false;
            if(set.count(query)){
                res.push_back(query);
                ok = true;
            }
            else{
                string lower_query = to_lower(query);
                if(map1.count(lower_query)){
                    res.push_back(map1[lower_query][0]);
                    ok = true;
                }
                else{
                    string novowel_query = replace_vowel(query);
                    if(map2.count(novowel_query)){
                        res.push_back(map2[novowel_query][0]);
                        ok = true;
                    }
                }
            }
            if(!ok) res.push_back("");
        }
        return res;
    }

private:
    string to_lower(const string& word){
        string res = "";
        for(char c: word) res += tolower(c);
        return res;
    }

    string replace_vowel(const string& word){
        string res = "";
        for(char c: word)
            if(vowels.count(tolower(c))) res += "#";
            else res += tolower(c);
        return res;
    }
};


int main() {

    return 0;
}