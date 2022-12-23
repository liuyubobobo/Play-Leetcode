/// Source : https://leetcode.com/problems/circular-sentence/description/
/// Author : liuyubobobo
/// Time   : 2022-12-19

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/// Simualtion
/// Time Complexity: O(|n|)
/// Space Complexity: O(|n|)
class Solution {
public:
    bool isCircularSentence(string sentence) {

        vector<string> words;
        for(int start = 0, i = 1; i <= sentence.size(); i ++){
            if(i == sentence.size() || sentence[i] == ' '){
                words.push_back(sentence.substr(start, i - start));
                start = i + 1;
                i = start;
            }
        }

        for(int i = 1; i < words.size(); i ++)
            if(words[i - 1].back() != words[i][0]) return false;
        return words.back().back() == words[0][0];
    }
};


int main() {

    return 0;
}
