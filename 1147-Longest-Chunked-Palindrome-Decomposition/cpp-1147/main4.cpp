/// Source : https://leetcode.com/problems/longest-chunked-palindrome-decomposition/
/// Author : liuyubobobo
/// Time   : 2019-08-04

#include <iostream>
#include <vector>

using namespace std;


/// Greedy - Iterative Implementation
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

public:
    int longestDecomposition(string text) {

        int n = text.size();
        int l = 0, r = n - 1, res = 0;
        string ls = "", rs = "";
        while(l < r){
            ls += text[l ++], rs = string(1, text[r --]) + rs;
            if(ls == rs) res += 2, ls = rs = "";
        }
        return res + (l == r || ls != "");
    }
};


int main() {

    cout << Solution().longestDecomposition("ghiabcdefhelloadamhelloabcdefghi") << endl;
    cout << Solution().longestDecomposition("aaa") << endl;

    return 0;
}