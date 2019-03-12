/// Source : https://leetcode.com/problems/implement-strstr/
/// Author : liuyubobobo
/// Time   : 2019-03-12

#include <iostream>
#include <vector>

using namespace std;


/// KMP based on DFA
/// Optimized DFA construction, using lps algorithm in main3 (or main4)
///
/// Time Complexity: O(m^2 * all_characters + n)
/// Sapce Complexity: O(m * all_characters)
///
/// TLE in Leetcode 28
class Solution {
public:
    int strStr(string haystack, string needle) {

        if(needle == "") return 0;
        if(haystack == "") return -1;

        int n = haystack.size(), m = needle.size();
        vector<vector<int>> dfa(256, vector<int>(m + 1, 0));

        // dfa construction
        dfa[needle[0]][0] = 1;
        vector<int> lps(m + 1, 0);
        for(int state = 1; state < m; state ++){
            dfa[needle[state]][state] = state + 1;
            for(int c = 0; c < 256; c ++)
                if(c != needle[state])
                    dfa[c][state] = get_state(needle, c, state, lps);
        }

        int state = 0;
        for(int i = 0; i < n; i ++){
            state = dfa[haystack[i]][state];
            if(state == m) return i - m + 1;
        }
        return -1;
    }

private:
    int get_state(const string& p, int c, int m, vector<int>& lps){

        for(int &e: lps) e = 0;

        int len = 0;
        for(int i = 1; i < m; i ++){
            while(len && p[i] != p[len])
                len = lps[len - 1];

            if(p[i] == p[len])
                lps[i] = ++ len;
        }

        while(len && c != p[len]) len = lps[len - 1];
        return c == p[len] ? len + 1 : 0;
    }
};


int main() {

    cout << Solution().strStr("hello", "ll") << endl; // 2
    cout << Solution().strStr("aaaaa", "bba") << endl; // -1
    cout << Solution().strStr("mississippi", "issip") << endl; // 4

    return 0;
}