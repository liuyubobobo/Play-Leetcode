/// Source : https://leetcode.com/problems/rearrange-characters-to-make-target-string/
/// Author : liuyubobobo
/// Time   : 2022-05-29

#include <iostream>
#include <vector>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int rearrangeCharacters(string s, string target) {

        vector<int> fs(26, 0);
        for(char c: s) fs[c - 'a'] ++;

        vector<int> ft(26, 0);
        for(char c: target) ft[c - 'a'] ++;

        int res = INT_MAX;
        for(int i = 0; i < 26; i ++)
            if(ft[i]) res = min(res, fs[i] / ft[i]);
        return res;
    }
};


int main() {

    return 0;
}
