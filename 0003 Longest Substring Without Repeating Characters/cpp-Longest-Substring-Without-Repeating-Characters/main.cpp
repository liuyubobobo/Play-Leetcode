/// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
/// Author : liuyubobobo
/// Time   : 2016-12-07


#include <iostream>
#include <vector>
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

        // assert no other characters except lower case alphabeta

        int hashtable[26] = {0};

        int l = 0, r;
        int res = 0;
        while( l < s.size() ){

            if( l > 0 ){
                for( ; l)
            }

            for( r = l ; r < s.size() && hashtable[s[r]-'a'] == 0 ; r ++ )
                hashtable[s[r]-'a'] += 1;
            //s[l...r) is a substring without repeat characters
            res = max( res , r-l );

            l ++;
        }
    }
};

int main() {

    int nums[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums_vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));

    vector<vector<int>> res = Solution().threeSum( nums_vec );
    for( int i = 0 ; i < res.size() ; i ++ ){
        for( int j = 0 ; j < res[i].size() ; j ++ )
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}