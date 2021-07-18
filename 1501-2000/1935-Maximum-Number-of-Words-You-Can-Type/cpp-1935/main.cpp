/// Source : https://leetcode.com/problems/maximum-number-of-words-you-can-type/
/// Author : liuyubobobo
/// Time   : 2021-07-17

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(|text| + |broken|)
/// Space Complexity: O(1)
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        vector<bool> broken(26, false);
        for(char c: brokenLetters) broken[c - 'a'] = true;

        int res = 0;
        for(int start = 0, i = 1; i <= text.size(); i ++)
            if(i == text.size() || text[i] == ' '){
                string word = text.substr(start, i - start);
                if(ok(word, broken)) res ++;

                start = i + 1;
                i = start;
            }
        return res;
    }

private:
    bool ok(const string& word, const vector<bool>& broken){

        for(char c: word)
            if(broken[c - 'a'])
                return false;
        return true;
    }
};


int main() {

    return 0;
}
