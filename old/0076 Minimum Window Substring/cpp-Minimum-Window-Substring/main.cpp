/// Source : https://leetcode.com/problems/minimum-window-substring/
/// Author : liuyubobobo
/// Time   : 2017-01-17

#include <iostream>
#include <cassert>

using namespace std;

/// Problem
/********************************************************************************************************
 *
 * Given a string S and a string T,
 * find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T, return the empty string "".
 *
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 ********************************************************************************************************/


/// Solution
/***********************************************************************************************
 * Using sliding window
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 ************************************************************************************************/

class Solution {
public:
    string minWindow(string s, string t) {

        int tFreq[256] = {0};
        for( int i = 0 ; i < t.size() ; i ++ )
            tFreq[t[i]] ++;

        int sFreq[256] = {0};
        int sCnt = 0;

        int minLength = s.size() + 1;
        int startIndex = -1;

        int l = 0, r = -1;
        while( l < s.size() ){

            if( r + 1 < s.size() && sCnt < t.size() ){

                sFreq[s[r+1]] ++;
                if( sFreq[s[r+1]] <= tFreq[s[r+1]] )
                    sCnt ++;
                r ++;
            }
            else{
                assert( sCnt <= t.size() );
                if( sCnt == t.size() && r - l + 1 < minLength ){
                    minLength = r - l + 1;
                    startIndex = l;
                }

                sFreq[s[l]] --;
                if( sFreq[s[l]] < tFreq[s[l]] )
                    sCnt --;
                l ++;
            }
        }

        if( startIndex != -1 )
            return s.substr( startIndex, minLength );

        return "";
    }
};

int main() {

    cout << Solution().minWindow( "ADOBECODEBANC" , "ABC" )<<endl;
    cout << Solution().minWindow( "a" , "aa" )<<endl;
    cout << Solution().minWindow( "aa" , "aa" )<<endl;
    cout << Solution().minWindow( "bba" , "ab" )<<endl;

    return 0;
}