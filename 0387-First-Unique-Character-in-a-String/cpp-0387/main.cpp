/// Source : https://leetcode.com/problems/first-unique-character-in-a-string/description/
/// Author : liuyubobobo
/// Time   : 2017-10-16

#include <iostream>

using namespace std;

/// Time Complexity: O(len(s))
/// Space Complexity: O(26)
class Solution {

public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        for(char c: s)
            freq[c-'a'] ++;

        for(int i = 0 ; i < s.size() ; i ++)
            if(freq[s[i]-'a'] == 1)
                return i;

        return -1;
    }
};

int main() {

    cout << Solution().firstUniqChar("leetcode") << endl;
    cout << Solution().firstUniqChar("loveleetcode") << endl;
    return 0;
}