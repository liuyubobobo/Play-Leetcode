/// Source : https://leetcode.com/problems/words-within-two-edits-of-dictionary/
/// Author : liuyubobobo
/// Time   : 2022-10-30

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(|queries| * |dict| * word_len)
/// Space Complexity: O(1)
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {

        vector<string> res;
        for(const string& word: queries){
            if(ok(word, dictionary)) res.push_back(word);
        }
        return res;
    }

private:
    bool ok(const string& word, const vector<string>& dict){

        for(const string& s: dict)
            if(diff(word, s) <= 2) return true;
        return false;
    }

    int diff(const string& s1, const string& s2){

        int n = s1.size(), res = 0;
        for(int i = 0; i < n; i ++)
            res += s1[i] != s2[i];
        return res;
    }
};


int main() {

    return 0;
}
