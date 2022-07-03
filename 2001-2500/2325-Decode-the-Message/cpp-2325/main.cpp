/// Source : https://leetcode.com/problems/decode-the-message/
/// Author : liuyubobobo
/// Time   : 2022-07-02

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(|key| + |message|)
/// Space Complexity: O(1)
class Solution {
public:
    string decodeMessage(string key, string message) {

        vector<bool> used(26, false);
        vector<char> table(26);
        char ch = 'a';
        for(char c: key){
            if(c == ' ' || used[c - 'a']) continue;
            table[c - 'a'] = ch ++;
            used[c - 'a'] = true;
        }

        for(char& c: message){
            if(c == ' ') continue;
            c = table[c - 'a'];
        }
        return message;
    }
};


int main() {

    return 0;
}
