/// Source : https://leetcode.com/problems/ransom-note/
/// Author : liuyubobobo
/// Time   : 2021-08-09

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n + m)
/// Space Complexity: O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        vector<int> f1(26, 0);
        for(char c: ransomNote) f1[c - 'a'] ++;

        vector<int> f2(26, 0);
        for(char c: magazine) f2[c - 'a'] ++;

        for(int i = 0; i < 26; i ++)
            if(f1[i] > f2[i]) return false;
        return true;
    }
};


int main() {

    return 0;
}
