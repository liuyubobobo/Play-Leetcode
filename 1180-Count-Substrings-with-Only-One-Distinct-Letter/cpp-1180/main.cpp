/// Source : https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/
/// Author : liuyubobobo
/// Time   : 2019-09-07

#include <iostream>

using namespace std;


/// Split and Mathematics
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int countLetters(string S) {

        int res = 0;
        for(int start = 0, i = start + 1; i <= S.size(); i ++)
            if(i == S.size() || S[i] != S[start]){
                int n = i - start;
                res += (1 + n) * n / 2;
                start = i;
                i = start;
            }
        return res;
    }
};


int main() {

    cout << Solution().countLetters("aaaba") << endl;
    // 8

    cout << Solution().countLetters("aaaaaaaaaa") << endl;
    // 55

    return 0;
}