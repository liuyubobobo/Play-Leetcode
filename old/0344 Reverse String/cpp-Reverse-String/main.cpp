/// Source : https://leetcode.com/problems/reverse-string/
/// Author : liuyubobobo
/// Time   : 2016-12-06


#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/********************************************************************************
 *
 * Write a function that takes a string as input and returns the string reversed.
 *
 * Example:
 * - Given s = "hello", return "olleh".
 **********************************************************************************/


/// Solution
/**************************************
 * Basic two pointers algorithm
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 **************************************/

class Solution {
public:
    string reverseString(string s) {
       int i = 0, j = s.size()-1;
       while( i < j )
           swap( s[i++] , s[j--] );
        return s;
    }
};

int main() {

    cout<<Solution().reverseString("hello");

    return 0;
}