/// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
/// Author : liuyubobobo
/// Time   : 2016-12-07


#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/******************************************************************************************
 *
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3.
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *******************************************************************************************/


/// Solution
/***********************************************************************************************
 * Using a hashtable and two pointer technique
 * find the subrange [l...r] in the s which makes the substring is longest and
 * without repeating characters
 *
 * Time Complexity: O(n)
 * Space Complexity: O(26)
 ************************************************************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if( s.size() == 0 )
            return 0;

        // The character set include more than just lower case characters
        int hashtable[256] = {0};

        int l = 0, r = 1;
        hashtable[s[l]] += 1;
        int res = 1;
        while( l < s.size() ){

            if( r == s.size() || hashtable[s[r]] == 1 ){
                res = max( res , r-l );
                while( l < s.size() ){
                    assert( hashtable[s[l]] == 1 );
                    hashtable[s[l]] --;
                    l ++;
                    if( r < s.size() && s[l-1] == s[r] )
                        break;
                }
            }
            else{
                hashtable[s[r]] ++;
                r ++;
            }
        }

        return res;
    }
};

int main() {

    cout<<Solution().lengthOfLongestSubstring("abcabcbb")<<endl;
    cout<<Solution().lengthOfLongestSubstring("bbbbb")<<endl;
    cout<<Solution().lengthOfLongestSubstring("pwwkew")<<endl;

    return 0;
}