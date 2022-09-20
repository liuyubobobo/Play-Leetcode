/// Source : https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/
/// Author : liuyubobobo
/// Time   : 2022-09-20

#include <iostream>

using namespace std;


/// String Split
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int longestContinuousSubstring(string s) {

        int n = s.size(), res = 0;
        for(int start = 0, i = 1; i <= n; i ++)
            if(i == n || s[i] - s[start] != i - start){
                res = max(res, i - start);
                start = i;
            }
        return res;
    }
};

int main() {

    return 0;
}
