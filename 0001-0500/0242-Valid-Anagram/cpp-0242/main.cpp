/// Source : https://leetcode.com/problems/valid-anagram/
/// Author : liuyubobobo
/// Time   : 2018-08-13

#include <iostream>

using namespace std;

/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};


int main() {

    cout << Solution().isAnagram("anagram", "nagaram") << endl;
    cout << Solution().isAnagram("rat", "car") << endl;
    cout << Solution().isAnagram("ab", "a") << endl;

    return 0;
}