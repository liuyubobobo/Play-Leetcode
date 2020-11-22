/// Source : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
/// Author : liuyubobobo
/// Time   : 2020-11-21

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(|word1| + |word2| + |s|)
/// Space Complexity: O(|s|)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        string a = "", b = "";
        for(const string& s: word1) a += s;
        for(const string& s: word2) b += s;
        return a == b;
    }
};


int main() {

    return 0;
}
