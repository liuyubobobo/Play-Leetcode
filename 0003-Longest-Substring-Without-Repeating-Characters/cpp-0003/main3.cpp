/// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
/// Author : liuyubobobo
/// Time   : 2017-11-14

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Sliding Window
// Using last[c] to record the last occurance of character c
// Using last[c] to quickly move the pointer l
// only r moved from left to right, Using n times calculation of res instead of 2*n times
//
// Time Complexity: O(len(s))
// Space Complexity: O(len(charset))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int last[256];
        memset(last, -1, sizeof(last));

        int l = 0, r = -1; // sliding window: s[l...r]
        int res = 0;
        while(r + 1 < s.size()){

            r ++;
            if(last[s[r]] != -1)
                l = max(l, last[s[r]] + 1);

            res = max(res, r - l + 1);
            last[s[r]] = r;
        }

        return res;
    }
};

int main() {

    cout << Solution().lengthOfLongestSubstring( "abcabcbb" )<<endl; //3
    cout << Solution().lengthOfLongestSubstring( "bbbbb" )<<endl;    //1
    cout << Solution().lengthOfLongestSubstring( "pwwkew" )<<endl;   //3
    cout << Solution().lengthOfLongestSubstring( "c" )<<endl;        //1
    cout << Solution().lengthOfLongestSubstring( "abba" )<<endl;     //2
    cout << Solution().lengthOfLongestSubstring( "" )<<endl;         //0

    return 0;
}