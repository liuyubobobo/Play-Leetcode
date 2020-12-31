/// Source : https://leetcode.com/problems/one-edit-distance/
/// Author : liuyubobobo
/// Time   : 2019-02-14

#include <iostream>
#include <cassert>

using namespace std;


/// Three One Pass Algorithms
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    bool isOneEditDistance(string s, string t) {

        if(s.size() == 0) return t.size() == 1;
        if(t.size() == 0) return s.size() == 1;

        if(s.size() + 1 == t.size())
            return can_add_char(s, t);
        else if(s.size() == t.size() + 1)
            return can_delete_char(s, t);
        else if(s.size() == t.size())
            return can_replace_char(s, t);
        return false;
    }

private:
    bool can_replace_char(const string& s, const string& t){

        assert(s.size() == t.size());

        int diff = 0;
        for(int i = 0; i < s.size(); i ++)
            diff += s[i] != t[i];
        return diff == 1;
    }

    bool can_delete_char(const string& s, const string& t){
        return can_add_char(t, s);
    }

    bool can_add_char(const string&s, const string& t){

        int si = 0, ti = 0;
        while(si < s.size() && ti < t.size() && s[si] == t[ti]) si ++, ti ++;
        si --;

        int sj = s.size() - 1, tj = t.size() - 1;
        while(sj > si && tj > ti && s[sj] == t[tj]) sj --, tj --;

//        cout << "si=" << si << " sj=" << sj << " ti=" << ti << " tj=" << tj << endl;
        return si == sj;
    }
};


int main() {

    string s1 = "ab", t1 = "acb";
    cout << Solution().isOneEditDistance(s1, t1) << endl;

    string s2 = "cab", t2 = "ad";
    cout << Solution().isOneEditDistance(s2, t2) << endl;

    return 0;
}