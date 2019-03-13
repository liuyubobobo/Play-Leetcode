/// Source : https://leetcode.com/problems/implement-strstr/
/// Author : liuyubobobo
/// Time   : 2019-03-12

#include <iostream>
#include <vector>

using namespace std;


/// BM Algorithm
/// Only bad character heuristic is used
///
/// Time Complexity: O(m * all_characters + n)
/// Sapce Complexity: O(m * all_characters)
class Solution {
public:
    int strStr(string haystack, string needle) {

        if(needle == "") return 0;
        if(haystack == "") return -1;

        int n = haystack.size(), m = needle.size();
        vector<int> bad(256, -1); // last occurrence of every character
        for(int i = 0; i < m; i ++)
            bad[needle[i]] = i;

        int i = 0;
        while(i <= n - m){

            int j = m - 1;
            for(; j >= 0; j --)
                if(needle[j] != haystack[i + j])
                    break;

            if(j < 0) return i;
            if(bad[haystack[i + j]] < 0)
                i += j + 1;
            else
                i += max(1, j - bad[haystack[i + j]]);
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