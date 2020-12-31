/// Source : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
/// Author : liuyubobobo
/// Time   : 2020-11-21

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers
/// Time Complexity: O(|s|)
/// Space Complexity: O(1)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        int p1 = 0, p2 = 0, i = 0, j = 0;
        while(p1 < word1.size() && p2 < word2.size()){

            if(word1[p1][i] != word2[p2][j]) return false;

            i ++;
            if(i == word1[p1].size()) p1 ++, i = 0;

            j ++;
            if(j == word2[p2].size()) p2 ++, j = 0;
        }
        return p1 == word1.size() && p2 == word2.size();
    }
};


int main() {

    return 0;
}
