/// Source : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/
/// Author : liuyubobobo
/// Time   : 2022-02-26

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(|s| + |t|)
/// Space Complexity: O(1)
class Solution {
public:
    int minSteps(string s, string t) {

        vector<int> sf(26, 0), tf(26, 0);
        for(char c: s) sf[c - 'a'] ++;
        for(char c: t) tf[c - 'a'] ++;

        int res = 0;
        for(int i = 0; i < 26; i ++)
            res += abs(sf[i] - tf[i]);
        return res;
    }
};


int main() {

    return 0;
}
