/// Source : https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
/// Author : liuyubobobo
/// Time   : 2021-08-14

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int res = 0;
        for(const string& e: patterns)
            res += word.find(e) != string::npos;
        return res;
    }
};


int main() {

    return 0;
}
