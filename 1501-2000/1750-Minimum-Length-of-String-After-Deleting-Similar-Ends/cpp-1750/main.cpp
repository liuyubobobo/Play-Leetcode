/// Source : https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>

using namespace std;


/// Two Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumLength(string s) {

        int l = 0, r = s.size() - 1;
        while(l < r && s[l] == s[r]){
            char c = s[l];
            while(l < r && s[l] == c) l ++;
            while(l <= r && s[r] == c) r --;
        }
        return r - l + 1;
    }
};


int main() {

    cout << Solution().minimumLength("ca") << endl;
    // 2

    cout << Solution().minimumLength("cabaabac") << endl;
    // 0

    cout << Solution().minimumLength("aabccabba") << endl;
    // 3

    return 0;
}
