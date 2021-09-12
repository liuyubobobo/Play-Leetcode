/// Source : https://leetcode.com/problems/reverse-prefix-of-word/
/// Author : liuyubobobo
/// Time   : 2021-09-11

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string reversePrefix(string word, char ch) {

        int p = word.find(ch);
        if(p == string::npos) return word;

        reverse(word.begin(), word.begin() + (p + 1));
        return word;
    }
};


int main() {

    return 0;
}
