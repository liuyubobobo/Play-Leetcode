/// Source : https://leetcode.com/problems/implement-strstr/
/// Author : liuyubobobo
/// Time   : 2016-12-05


#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/*****************************************************************************************************
 *
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack,
 * or -1 if needle is not part of haystack.
 *****************************************************************************************************/


/// Solution
/**************************************************************************************
 * The basic O(s1*s2) Implementation
 *
 * Time Complexity: O(s1*s2)
 * Space Complexity: O(1)
 **************************************************************************************/

class Solution {
public:
    int strStr(string haystack, string needle) {

        int len1 = haystack.size();
        int len2 = needle.size();

        for( int i = 0 ; i <= len1 - len2 ; i ++ ){
            bool ok = true;
            for( int j = i ; j < i + len2 ; j ++ )
                if( haystack[j] != needle[j-i] ){
                    ok = false;
                    break;
                }
            if( ok )
                return i;
        }

        return -1;
    }
};

int main() {

    string s1 = "ababc";
    string s2 = "bab";

    cout<<Solution().strStr(s1, s2)<<endl;

    return 0;
}