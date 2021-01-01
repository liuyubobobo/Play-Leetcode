/// Source : https://leetcode.com/problems/palindrome-permutation/
/// Author : liuyubobobo
/// Time   : 2021-01-01

#include <iostream>
#include <vector>
using namespace std;


/// Statistics
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool canPermutePalindrome(string s) {

        vector<int> freq(256, 0);
        for(char c: s)
            freq[c] ++;

        int even = 0, odd = 0;
        for(int e: freq)
            if(e % 2) odd ++;
            else even ++;

        return odd <= 1;
    }
};


int main() {

    return 0;
}
