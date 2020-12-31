/// Source : https://leetcode.com/problems/verifying-an-alien-dictionary/
/// Author : liuyubobobo
/// Time   : 2018-12-08

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Transform and Compare
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        unordered_map<char, char> map;
        for(int i = 0; i < order.size(); i ++)
            map[order[i]] = 'a' + i;

        for(string&word: words)
            for(char& c: word)
                c = map[c];

        for(int i = 1; i < words.size(); i ++)
            if(words[i - 1] > words[i])
                return false;
        return true;
    }
};


int main() {

    return 0;
}