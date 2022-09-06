/// Source : https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/
/// Author : liuyubobobo
/// Time   : 2022-09-05

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Compelxity: O(n)
class Solution {
public:
    int uniqueLetterString(string s) {

        vector<vector<int>> pos(26);
        for(int i = 0; i < s.size(); i ++)
            pos[s[i] - 'A'].push_back(i);

        vector<int> indexes(26, 0);

        int res = 0;
        for(int start = 0; start < s.size(); start ++){
            for(int c = 0; c < 26; c ++){
                int a = indexes[c];
                if(a >= pos[c].size()) continue;

                if(a + 1 >= pos[c].size()) res += (s.size() - pos[c][a]);
                else res += pos[c][a + 1] - pos[c][a];

                if(pos[c][a] == start) indexes[c] ++;
            }
        }
        return res;
    }
};

int main() {

    cout << Solution().uniqueLetterString("ABC") << '\n';
    // 10

    cout << Solution().uniqueLetterString("ABA") << '\n';
    // 8

    cout << Solution().uniqueLetterString("LEETCODE") << '\n';
    // 92

    return 0;
}
