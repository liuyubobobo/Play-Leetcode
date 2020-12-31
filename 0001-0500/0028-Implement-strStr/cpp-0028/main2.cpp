/// Source : https://leetcode.com/problems/implement-strstr/
/// Author : liuyubobobo
/// Time   : 2019-03-12

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Rabin-Karp
/// Time Complexity: O(n * m)
/// Sapce Complexity: O(m)
class Solution {

private:
    const int MOD = 1e9 + 7;
    const int base = 256;

public:
    int strStr(string haystack, string needle) {

        if(needle == "") return 0;
        if(haystack == "") return -1;

        int n = haystack.size(), m = needle.size();
        if(n < m) return -1;

        int h = 1, txthash = 0, patternhash = 0;
        for(int i = 0; i < m - 1; i ++){
            h = h * 256ll % MOD;
            txthash = (txthash * 256ll + haystack[i]) % MOD;
            patternhash = (patternhash * 256ll + needle[i]) % MOD;
        }
        patternhash = (patternhash * 256ll + needle[m - 1]) % MOD;

        for(int i = m - 1; i < n; i ++){
            txthash = (txthash * 256ll + haystack[i]) % MOD;
            if(txthash == patternhash && same(haystack, i - m + 1, i, needle))
                return i - m + 1;

            txthash -= haystack[i - m + 1] * (long long)h % MOD;
            if(txthash < 0) txthash += MOD;
        }
        return -1;
    }

private:
    bool same(const string& s, int start, int end, const string& t){
//        assert(end - start + 1 == t.size());
        for(int i = start; i <= end; i ++)
            if(s[i] != t[i - start])
                return false;
        return true;
    }
};


int main() {

//    cout << Solution().strStr("hello", "ll") << endl; // 2
    cout << Solution().strStr("aaaaa", "bba") << endl; // -1
//    cout << Solution().strStr("mississippi", "issip") << endl; // 4

    return 0;
}