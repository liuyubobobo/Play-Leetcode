/// Source : https://leetcode.com/problems/longest-chunked-palindrome-decomposition/
/// Author : liuyubobobo
/// Time   : 2019-08-04

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

private:
    string s;
    int n;

public:
    int longestDecomposition(string text) {

        n = text.size();
        s = text;
        return go(0);
    }

private:
    int go(int l){

        if(n % 2){
            if(l == n / 2) return 1;
            if(l > n /2 ) return 0;
        }
        else if(l >= n / 2) return 0;

        for(int len = 1; l + len <= n / 2; len ++)
            if(s.substr(l, len) == s.substr(n - l - len, len))
               return 2 + go(l + len);
        return 1;
    }
};


int main() {

    cout << Solution().longestDecomposition("ghiabcdefhelloadamhelloabcdefghi") << endl;
    cout << Solution().longestDecomposition("aaa") << endl;

    return 0;
}