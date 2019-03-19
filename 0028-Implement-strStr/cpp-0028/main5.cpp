/// Source : https://leetcode.com/problems/implement-strstr/
/// Author : liuyubobobo
/// Time   : 2019-03-12

#include <iostream>
#include <vector>

using namespace std;


/// KMP based on DFA
///
/// Time Complexity: O(m * all_characters + n)
/// Sapce Complexity: O(m * all_characters)
class Solution {
public:
    int strStr(string haystack, string needle) {

        if(needle == "") return 0;
        if(haystack == "") return -1;

        int n = haystack.size(), m = needle.size();
        vector<vector<int>> dfa(256, vector<int>(m + 1, 0));

        // dfa construction
        dfa[needle[0]][0] = 1;
        int lps = 0;
        for(int state = 1; state < m; state ++){
            for(int c = 0; c < 256; c ++)
                dfa[c][state] = dfa[c][lps];

            dfa[needle[state]][state] = state + 1;

            lps = dfa[needle[state]][lps];
        }

        int state = 0;
        for(int i = 0; i < n; i ++){
            state = dfa[haystack[i]][state];
            if(state == m) return i - m + 1;

        }
        return -1;
    }
};


int main() {

    cout << Solution().strStr("hello", "ll") << endl; // 2
    cout << Solution().strStr("aaaaa", "bba") << endl; // -1
    cout << Solution().strStr("mississippi", "issip") << endl; // 4

    return 0;
}