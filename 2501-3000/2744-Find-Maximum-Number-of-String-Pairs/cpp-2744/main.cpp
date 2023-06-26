/// Source : https://leetcode.com/problems/find-maximum-number-of-string-pairs/description/
/// Author : liuyubobobo
/// Time   : 2023-06-25

#include <iostream>
#include <vector>

using namespace std;


/// Using Hash Table
/// Time Complexity: O(n + 26 * 26)
/// Space Complexity: O(26 * 26)
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {

        vector<vector<int>> f(26, vector<int>(26, 0));
        for(const string& word: words) {
            f[word[0] - 'a'][word[1] - 'a'] ++;
        }

        int res = 0;
        for(int i = 0; i < 26; i ++)
            for(int j = i + 1; j < 26; j ++) res += min(f[i][j], f[j][i]);
        for(int i = 0; i < 26; i ++) res += f[i][i] / 2;
        return res;
    }
};

int main() {

    return 0;
}
