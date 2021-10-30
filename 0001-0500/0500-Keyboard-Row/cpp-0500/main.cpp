/// Source : https://leetcode.com/problems/keyboard-row/
/// Author : liuyubobobo
/// Time   : 2021-10-30

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    vector<string> findWords(vector<string>& words) {

        vector<string> keyboard = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<int> key(26);
        for(int i = 0; i < 3; i ++)
            for(char c: keyboard[i]) key[c - 'a'] = i;

        vector<string> res;
        for(const string& word: words)
            if(ok(key, word)) res.push_back(word);
        return res;
    }

private:
    bool ok(const vector<int>& key, const string& word){

        int t = key[tolower(word[0]) - 'a'];
        for(int i = 1; i < word.size(); i ++)
            if(key[tolower(word[i]) - 'a'] != t) return false;
        return true;
    }
};


int main() {

    return 0;
}
