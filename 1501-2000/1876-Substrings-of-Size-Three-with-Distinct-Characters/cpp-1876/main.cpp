/// Source : https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
/// Author : liuyubobobo
/// Time   : 2021-05-28

#include <iostream>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int countGoodSubstrings(string s) {

        int res = 0;
        for(int i = 2; i < s.size(); i ++)
            res += ((s[i-2]!=s[i-1]) && (s[i-1]!=s[i]) && (s[i]!=s[i-2]));
        return res;
    }
};


int main() {

    return 0;
}
