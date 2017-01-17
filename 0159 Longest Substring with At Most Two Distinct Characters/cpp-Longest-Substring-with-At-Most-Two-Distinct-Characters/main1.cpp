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


/// Solution 1
/**********************************************************************************
 * Using two pointer technique.
 * Recording how many different characters in the current string by map.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 **********************************************************************************/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {

        unordered_map<char, int> map;
        int l = 0, r = 0;
        int res = 0;
        while( r <= s.size() ){

            if( r == s.size() || (map.size() == 2 && map.find(s[r]) == map.end() ) ){
                res = max( res , r-l );
                while( map.size() >= 2 ){
                    if( map[s[l]] == 1 )
                        map.erase( s[l] );
                    else
                        map[s[l]] --;
                    l ++;
                }

                if( r == s.size() )
                    break;
            }
            else{
                if( map.find(s[r]) == map.end() )
                    map[s[r]] = 1;
                else
                    map[s[r]] += 1;
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