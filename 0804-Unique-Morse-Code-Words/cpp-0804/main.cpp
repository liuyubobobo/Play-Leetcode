/// Source : https://leetcode.com/problems/unique-morse-code-words/description/
/// Author : liuyubobobo
/// Time   : 2018-03-24

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/// Using Hash Set
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> bag;
        for(const string& word: words){

            string code = "";
            for(char c: word)
                code += morse[c - 'a'];
            bag.insert(code);
        }
        return bag.size();
    }
};

int main() {

    vector<string> words = {"gin", "zen", "gig", "msg"};
    cout << Solution().uniqueMorseRepresentations(words) << endl;

    return 0;
}