/// Source : https://leetcode.com/problems/implement-strstr/
/// Author : liuyubobobo
/// Time   : 2019-03-12

#include <iostream>
#include <vector>

using namespace std;


/// KMP based on lps
/// Another way to compute lps, maybe more intuitive :-)
/// See here for details:
/// https://www.coursera.org/lecture/algorithms-on-strings/computing-prefix-function-5lDsK
///
/// Time Complexity: O(n + m)
/// Sapce Complexity: O(m)
class Solution {
public:
    int strStr(string haystack, string needle) {

        if(haystack == "") return needle == "" ? 0 : -1;
        if(needle == "") return 0;

        int n = haystack.size(), m = needle.size();
        vector<int> lps = getLPS(needle, m); // longest proper prefix which is also suffix

        int i = 0, j = 0;
        while(i < n){

            if(haystack[i] == needle[j]) {
                i++, j++;

                if (j == needle.size())
                    return i - needle.size();
            }

            else if(j) j = lps[j - 1] ;
            else i ++;
        }
        return -1;
    }

private:
    vector<int> getLPS(const string& pattern, int m){

        vector<int> lps(m, 0);
        // lps[0] = 0;

        int len = 0;
        for(int i = 1; i < m; i ++){
            while(len && pattern[i] != pattern[len])
                len = lps[len - 1];

            if(pattern[i] == pattern[len])
                lps[i] = ++ len;
        }
        return lps;
    }
};


int main() {

    cout << Solution().strStr("hello", "ll") << endl; // 2
    cout << Solution().strStr("aaaaa", "bba") << endl; // -1
    cout << Solution().strStr("mississippi", "issip") << endl; // 4

    return 0;
}