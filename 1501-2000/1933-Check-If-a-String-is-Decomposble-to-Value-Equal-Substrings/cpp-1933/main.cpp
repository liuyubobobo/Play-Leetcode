/// Source : https://leetcode.com/problems/check-if-a-string-is-decomposble-to-value-equal-substrings/
/// Author : liuyubobobo
/// Time   : 2021-07-02

#include <iostream>

using namespace std;


/// Split
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool isDecomposable(string s) {

        int two = 0;
        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] != s[start]){
                int len = i - start;
                if(len % 3 == 1) return false;
                if(len % 3 == 2) two ++;
                if(two > 1) return false;

                start = i;
                i = start;
            }
        return two == 1;
    }
};


int main() {

    return 0;
}
