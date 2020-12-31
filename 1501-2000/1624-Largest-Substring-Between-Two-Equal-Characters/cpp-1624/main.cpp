/// Source : https://leetcode.com/problems/largest-substring-between-two-equal-characters/
/// Author : liuyubobobo
/// Time   : 2020-10-17

#include <iostream>
#include <vector>

using namespace std;


/// Hash
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        vector<vector<int>> pos(26);
        for(int i = 0; i < s.size(); i ++)
            pos[s[i] - 'a'].push_back(i);

        int res = -1;
        for(int i = 0; i < 26; i ++)
            if(pos[i].size() > 1) res = max(res, pos[i].back() - pos[i][0] - 1);
        return res;
    }
};


int main() {

    cout << Solution().maxLengthBetweenEqualCharacters("aa") << endl;
    // 0

    cout << Solution().maxLengthBetweenEqualCharacters("abca") << endl;
    // 2

    cout << Solution().maxLengthBetweenEqualCharacters("cbzxy") << endl;
    // -1

    cout << Solution().maxLengthBetweenEqualCharacters("cabbac") << endl;
    // 4

    return 0;
}
