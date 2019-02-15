/// Source : https://leetcode.com/problems/one-edit-distance/
/// Author : liuyubobobo
/// Time   : 2019-02-14

#include <iostream>
#include <cassert>

using namespace std;


/// One Pass Algorithms
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    bool isOneEditDistance(string s, string t) {

        if(s.size() == 0) return t.size() == 1;
        if(t.size() == 0) return s.size() == 1;

        int si = 0, ti = 0;
        while(si < s.size() && ti < t.size() && s[si] == t[ti]) si ++, ti ++;
        si --, ti --;

        int sj = s.size() - 1, tj = t.size() - 1;
        while(sj > si && tj > ti && s[sj] == t[tj]) sj --, tj --;

        if(si + 1 == sj && ti == tj) return true;
        if(ti + 1 == tj && si == sj) return true;
        if(si + 1 == sj && ti + 1 == tj) return true;
        return false;
    }
};


int main() {

    string s1 = "ab", t1 = "acb";
    cout << Solution().isOneEditDistance(s1, t1) << endl;

    string s2 = "cab", t2 = "ad";
    cout << Solution().isOneEditDistance(s2, t2) << endl;

    return 0;
}