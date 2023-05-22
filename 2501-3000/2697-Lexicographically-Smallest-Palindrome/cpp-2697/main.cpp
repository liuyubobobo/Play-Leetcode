/// Source : https://leetcode.com/problems/lexicographically-smallest-palindrome/description/
/// Author : liuyubobobo
/// Time   : 2023-05-21

#include <iostream>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string makeSmallestPalindrome(string s) {

        int n = s.size();
        for(int i = 0, j = n - 1; i < j; i ++, j --){
            char min_char = min(s[i], s[j]);
            s[i] = s[j] = min_char;
        }
        return s;
    }
};


int main() {

    return 0;
}
