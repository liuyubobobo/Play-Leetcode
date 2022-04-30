/// Source : https://leetcode.com/problems/count-prefixes-of-a-given-string/
/// Author : liuyubobobo
/// Time   : 2022-04-30

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * |s|)
/// Space Complexity: O(|s|)
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {

        int res = 0;
        for(const string& word: words){
            res += (word.size() <= s.size() && s.substr(0, word.size()) == word);
        }
        return res;
    }
};


int main() {

    return 0;
}
