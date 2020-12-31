/// Source : https://leetcode.com/problems/construct-k-palindrome-strings/
/// Author : liuyubobobo
/// Time   : 2020-04-04

#include <iostream>
#include <vector>

using namespace std;


/// Using Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool canConstruct(string s, int k) {

        if(s.size() < k) return false;
        if(s.size() == k) return true;

        vector<int> freq(26, 0);
        for(char c: s) freq[c - 'a'] ++;

        int odd = 0;
        for(int e: freq) if(e % 2) odd ++;

        while(odd && k) k --, odd --;
        return odd < 1;
    }
};


int main() {

    cout << Solution().canConstruct("annabelle", 2) << endl;
    // true

    cout << Solution().canConstruct("leetcode", 3) << endl;
    // false

    cout << Solution().canConstruct("abcdefghijklmnopqrstuvwxyz", 25) << endl;
    // false

    return 0;
}