/// Source : https://leetcode.com/problems/minimum-number-of-keypresses/
/// Author : liuyubobobo
/// Time   : 2022-05-11

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumKeypresses(string s) {

        vector<int> f(26, 0);
        for(char c: s) f[c - 'a'] ++;

        sort(f.begin(), f.end(), greater<int>());

        int res = 0;
        for(int i = 0; i < 26; i ++)
            res += f[i] * (i / 9 + 1);
        return res;
    }
};


int main() {

    return 0;
}
