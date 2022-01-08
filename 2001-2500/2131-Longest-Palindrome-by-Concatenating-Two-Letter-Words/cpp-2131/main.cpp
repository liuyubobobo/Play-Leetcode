/// Source : https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
/// Author : liuyubobobo
/// Time   : 2022-01-08

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {

        vector<vector<int>> f(26, vector<int>(26, 0));
        for(const string& word: words)
            f[word[0] - 'a'][word[1] - 'a'] ++;

        int res = 0;
        for(int i = 0; i < 26; i ++)
            for(int j = i + 1; j < 26; j ++)
                res += min(f[i][j], f[j][i]) * 4;

        bool middle = false;
        for(int i = 0; i < 26; i ++){
            res += f[i][i] / 2 * 2 * 2;
            if(f[i][i] % 2) middle = true;
        }

        if(middle) res += 2;
        return res;
    }
};


int main() {

    return 0;
}
