/// Source : https://leetcode.com/problems/valid-palindrome/
/// Author : liuyubobobo
/// Time   : 2016-12-05


#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/********************************************************************************
 *
 * Given a string, determine if it is a palindrome,
 * considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * - Have you consider that the string might be empty?
 *   This is a good question to ask during an interview.
 * - For the purpose of this problem, we define empty string as valid palindrome.
 **********************************************************************************/


/// Solution
/*****************************************************************************
 * Using Two Pointers
 *
 * Time Complexity:  O(s)
 * Space Complexity: O(1)
 ******************************************************************************/

class Solution {
public:
    bool isPalindrome(string s) {

        int i = nextCharacterIndex(s, -1) , j = preCharacterIndex(s, s.size());
        while( i <= j ){

            if( tolower(s[i]) != tolower(s[j]) )
                return false;

            i = nextCharacterIndex( s , i );
            j = preCharacterIndex( s , j );
        }

        return true;
    }

private:
    int nextCharacterIndex( const string &s , int index ){

        int res = index + 1;
        for( res = index + 1 ; res < s.size() ; res ++ )
            if( isalnum(s[res]) )
                return res;
        return res;
    }

    int preCharacterIndex( const string &s , int index ){

        int res = index - 1;
        for( res = index - 1 ; res >= 0 ; res -- )
            if( isalnum(s[res]) )
                return res;
        return res;
    }
};


int main() {

    cout<<Solution().isPalindrome( "A man, a plan, a canal: Panama" )<<endl;
    cout<<Solution().isPalindrome( "race a car" )<<endl;

    return 0;
}