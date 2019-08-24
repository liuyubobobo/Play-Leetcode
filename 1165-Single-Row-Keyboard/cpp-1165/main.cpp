/// Source : https://leetcode.com/problems/single-row-keyboard/
/// Author : liuyubobobo
/// Time   : 2019-08-24

#include <iostream>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: O(|word|)
/// Space Complexity: O(1)
class Solution {
public:
    int calculateTime(string keyboard, string word) {

        unordered_map<char, int> map;
        for(int i = 0; i < keyboard.size(); i ++)
            map[keyboard[i]] = i;

        int cur = 0, res = 0;
        for(char c: word)
            res += abs(cur - map[c]), cur = map[c];
        return res;
    }
};


int main() {

    return 0;
}