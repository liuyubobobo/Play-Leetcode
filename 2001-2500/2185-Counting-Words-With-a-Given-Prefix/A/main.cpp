/// Source : https://leetcode.com/problems/counting-words-with-a-given-prefix/
/// Author : liuyubobobo
/// Time   : 2022-02-26

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * len)
/// Space Complexity: O(1)
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        int res = 0;
        for(const string& word: words)
            if(word.find(pref) == 0) res ++;
        return res;
    }
};


int main() {

    return 0;
}
