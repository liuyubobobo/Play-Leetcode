/// Source : https://leetcode.com/problems/next-palindrome-using-same-digits/
/// Author : liuyubobobo
/// Time   : 2021-05-03

#include <iostream>
#include <algorithm>

using namespace std;


/// next_permutation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string nextPalindrome(string num) {

        int sz = num.size();
        string half = num.substr(0, sz / 2);

        if(!next_permutation(half.begin(), half.end())) return "";

        string post = half;
        reverse(post.begin(), post.end());
        return half + (sz % 2 ? (string(1, num[sz / 2])) : "") + post;
    }
};

int main() {

    cout << Solution().nextPalindrome("1221") << endl;
    // 2112

    cout << Solution().nextPalindrome("32123") << endl;
    // ""

    cout << Solution().nextPalindrome("45544554") << endl;
    // 54455445

    cout << Solution().nextPalindrome("23143034132") << endl;
    // 23314041332

    return 0;
}
