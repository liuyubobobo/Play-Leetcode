/// Source : https://leetcode.com/problems/determine-if-string-halves-are-alike/
/// Author : liuyubobobo
/// Time   : 2020-12-29

#include <iostream>
#include <unordered_set>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool halvesAreAlike(string s) {

        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int n = s.size(), l = 0, r = 0;
        for(int i = 0; i < n / 2; i ++) l += set.count(s[i]);
        for(int i = n / 2; i < n; i ++) r += set.count(s[i]);
        return l == r;
    }
};


int main() {

    return 0;
}
