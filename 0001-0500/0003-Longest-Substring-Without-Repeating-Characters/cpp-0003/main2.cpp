/// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
/// Author : liuyubobobo
/// Time   : 2017-11-14

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Sliding Window
// Another Implementation
//
// Time Complexity: O(len(s))
// Space Complexity: O(len(charset))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int freq[256] = {0};

        int l = 0, r = -1; // sliding window: s[l...r]
        int res = 0;

        while(r + 1 < s.size()){

            while(r + 1 < s.size() && freq[s[r + 1]] == 0)
                freq[s[++r]] ++;

            res = max(res, r - l + 1);

            if(r + 1 < s.size()){
                freq[s[++r]] ++;
                assert(freq[s[r]] == 2);
                while(l <= r && freq[s[r]] == 2)
                    freq[s[l++]] --;
            }
        }

        return res;
    }
};

int main() {

    cout << Solution().lengthOfLongestSubstring( "abcabcbb" )<<endl; //3
    cout << Solution().lengthOfLongestSubstring( "bbbbb" )<<endl;    //1
    cout << Solution().lengthOfLongestSubstring( "pwwkew" )<<endl;   //3
    cout << Solution().lengthOfLongestSubstring( "c" )<<endl;        //1
    cout << Solution().lengthOfLongestSubstring( "" )<<endl;         //0

    return 0;
}