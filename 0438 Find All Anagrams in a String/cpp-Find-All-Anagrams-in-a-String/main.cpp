/// Source : https://leetcode.com/problems/find-all-anagrams-in-a-string/
/// Author : liuyubobobo
/// Time   : 2017-01-18

#include <iostream>
#include <vector>

using namespace std;

/// Problem
/********************************************************************************
 *
 * Given a string s and a non-empty string p,
 * find all the start indices of p's anagrams in s.
 *
 * Strings consists of lowercase English letters only
 * and the length of both strings s and p will not be larger than 20,100.
 *
 * The order of output does not matter.
 *
 * Example 1:
 *
 * Input: s: "cbaebabacd" p: "abc"
 * Output:  [0, 6]
 *
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 *
 * Example 2:
 *
 * Input: s: "abab" p: "ab"
 * Output: [0, 1, 2]
 *
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 **********************************************************************************/


/// Solution
/**************************************
 * Sliding window solution
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 **************************************/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;

        int pfreq[256] = {0};
        for( int i = 0 ; i < p.size() ; i ++ )
            pfreq[p[i]] ++;

        int sfreq[256] = {0};
        int cnt = 0;

        int l = 0, r= -1;
        while( l < s.size() ){
            if( r + 1 < s.size() && sfreq[s[r+1]] + 1 <= pfreq[s[r+1]]){
                sfreq[s[++r]] ++;
                cnt ++;
            }
            else{
                sfreq[s[l++]] --;
                cnt --;
            }

            if( cnt == p.size() )
                res.push_back( l );
        }

        return res;
    }
};

void printVector( const vector<int> &vec){

    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;

    return;
}

int main() {

    vector<int> res1 = Solution().findAnagrams("cbaebabacd", "abc");
    printVector( res1 );
    vector<int> res2 = Solution().findAnagrams("abab", "ab");
    printVector( res2 );

    return 0;
}