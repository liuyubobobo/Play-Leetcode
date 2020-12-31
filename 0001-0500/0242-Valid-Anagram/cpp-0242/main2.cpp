/// Source : https://leetcode.com/problems/valid-anagram/
/// Author : liuyubobobo
/// Time   : 2017-01-17

#include <iostream>

using namespace std;

/// Using Hashtable
/// Time Complexity: O(n)
/// Space Complexity: O(26)
class Solution {
public:
    bool isAnagram(string s, string t) {

        if( s.size() != t.size() )
            return false;

        int freq[26] = {0};
        for( int i = 0 ; i < s.size() ; i ++ )
            freq[s[i]-'a'] ++;

        for( int i = 0 ; i < t.size() ; i ++ ){
            freq[t[i]-'a'] --;
            if( freq[t[i]-'a'] < 0 )
                return false;
        }

        return true;
    }
};


int main() {

    cout << Solution().isAnagram("anagram", "nagaram") << endl;
    cout << Solution().isAnagram("rat", "car") << endl;
    cout << Solution().isAnagram("ab", "a") << endl;

    return 0;
}