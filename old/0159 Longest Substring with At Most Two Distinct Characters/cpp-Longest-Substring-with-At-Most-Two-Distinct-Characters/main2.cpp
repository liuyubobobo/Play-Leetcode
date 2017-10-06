#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <cmath>

using namespace std;


/// Problem
/***********************************************************************************************
 * Given a string,
 * find the length of the longest substring T that contains at most 2 distinct characters.
 *
 * For example, Given s = “eceba”,
 *
 * T is "ece" which its length is 3.
 ***********************************************************************************************/


/// Solution 2
/********************************************************************************************
 * Using two pointer technique.
 * Using self-built hashtable to record how many different characters in the current string
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 ********************************************************************************************/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {

        int hashtable[256] = {0};
        int l = 0, r = 0;
        int res = 0;
        int count = 0;
        while( r <= s.size() ){

            if( r == s.size() || (count == 2 && !hashtable[s[r]] ) ){
                res = max( res , r-l );
                while( count >= 2 ){
                    hashtable[s[l]] --;
                    if( hashtable[s[l]] == 0 )
                        count --;
                    l ++;
                }

                if( r == s.size() )
                    break;
            }
            else{
                hashtable[s[r]] ++;
                if( hashtable[s[r]] == 1 )
                    count ++;
                r ++;
            }
        }

        return res;
    }
};

int main() {

    cout<<Solution().lengthOfLongestSubstringTwoDistinct("eceba")<<endl;

    cout<<Solution().lengthOfLongestSubstringTwoDistinct("a")<<endl;

    return 0;
}