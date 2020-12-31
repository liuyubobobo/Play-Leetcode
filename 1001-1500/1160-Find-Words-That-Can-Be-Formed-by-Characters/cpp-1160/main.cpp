/// Source : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
/// Author : liuyubobobo
/// Time   : 2019-08-17

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        vector<int> freq(26, 0);
        for(char c: chars)
            freq[c - 'a'] ++;

        int res = 0;
        for(const string& word: words)
            if(ok(word, freq)) res += word.size();
        return res;
    }

private:
    bool ok(const string& s, const vector<int>& freq){

        vector<int> f(26, 0);
        for(char c: s)
            f[c - 'a'] ++;

        for(int i = 0; i < 26; i ++)
            if(f[i] > freq[i]) return false;
        return true;
    }
};


int main() {

    return 0;
}