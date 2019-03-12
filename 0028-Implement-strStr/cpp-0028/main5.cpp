/// Source : https://leetcode.com/problems/implement-strstr/
/// Author : liuyubobobo
/// Time   : 2019-03-12

#include <iostream>
#include <vector>

using namespace std;


/// KMP based on DFA
/// Naive DFA construction
///
/// Time Complexity: O(m^3 * all_characters + n)
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
        for(int state = 1; state < m; state ++){
            dfa[needle[state]][state] = state + 1;
            for(int c = 0; c < 256; c ++)
                if(c != needle[state])
                    dfa[c][state] = get_state(needle, c, state);
        }

        int state = 0;
        for(int i = 0; i < n; i ++){
            state = dfa[haystack[i]][state];
            if(state == m) return i - m + 1;
        }
        return -1;
    }

private:
    int get_state(const string& p, int c, int m){

        string s = p.substr(0, m) + string(1, c);
        for(int len = s.size() - 1; len > 0; len --)
            if(same(s, 0, s.size() - len, len))
                return len;
        return 0;
    }

    bool same(const string& s, int s1, int s2, int l){
        for(int i = 0; i < l; i ++)
            if(s[s1 + i] != s[s2 + i])
                return false;
        return true;
    }
};


int main() {

    cout << Solution().strStr("hello", "ll") << endl; // 2
    cout << Solution().strStr("aaaaa", "bba") << endl; // -1
    cout << Solution().strStr("mississippi", "issip") << endl; // 4

    return 0;
}