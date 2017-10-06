/// Source : https://leetcode.com/problems/sort-characters-by-frequency/
/// Author : liuyubobobo
/// Time   : 2017-01-17

#include <iostream>

using namespace std;

/// Problem
/********************************************************************************************************
 *
 * Given a string, sort it in decreasing order based on the frequency of characters.
 *
 * Example 1:
 *
 * Input: "tree"
 * Output: "eert"
 *
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'.
 * Therefore "eetr" is also a valid answer.
 *
 * Example 2:
 *
 * Input: "cccaaa"
 * Output: "cccaaa"
 *
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 *
 * Example 3:
 *
 * Input: "Aabb"
 * Output: "bbAa"
 *
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 ********************************************************************************************************/


/// Solution
/***********************************************************************************************
 * Using Counting Sort
 *
 * Time Complexity: O(n)
 * Space Complexity: O(256)
 ************************************************************************************************/

class Solution {
public:
    string frequencySort(string s) {

        pair<char, int> freq[256];
        for( int i = 0 ; i < 256 ; i ++ ){
            freq[i].first = i;
            freq[i].second = 0;
        }

        for( int i = 0 ; i < s.size() ; i ++ )
            freq[s[i]].second ++;

        sort( freq, freq+256, cmpFreq );

        int index = 0;
        for( int i = 0 ; i < s.size() ; i ++ ){
            while( !freq[index].second )
                index ++;
            s[i] = freq[index].first;
            freq[index].second --;
        }

        return s;
    }

private:
    static bool cmpFreq( const pair<char,int> &a, const pair<char, int> &b){
        return a.second > b.second;
    }
};

int main() {

    cout << Solution().frequencySort("tree")<<endl;
    cout << Solution().frequencySort("cccaaa")<<endl;
    cout << Solution().frequencySort("Aabb")<<endl;

    return 0;
}