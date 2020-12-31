/// Source : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
/// Author : liuyubobobo
/// Time   : 2019-02-10

#include <iostream>
#include <vector>

using namespace std;


/// Using HashMap
/// Time Complexity: O(|s| + |t|)
/// Space Complexity: O(1)
class Solution {
public:
    int minSteps(string s, string t) {

        vector<int> v(26, 0);
        for(char c: s) v[c - 'a'] ++;
        for(char c: t) v[c - 'a'] --;

        int res = 0;
        for(int e: v) res += abs(e);
        return res / 2;
    }
};


int main() {

    return 0;
}
