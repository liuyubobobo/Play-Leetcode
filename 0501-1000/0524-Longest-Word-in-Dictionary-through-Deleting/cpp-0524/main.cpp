/// Source : https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
/// Author : liuyubobobo
/// Time   : 2021-02-22

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force + Two Pointers
/// Time Complexity: O(n * |word|)
/// Space Complexity: O(1)
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {

        string res = "";
        for(const string& t: d)
            if(ok(s, t) && (t.size() > res.size() || (t.size() == res.size() && t < res)))
                res = t;
        return res;
    }

private:
    bool ok(const string& s, const string& t){

        int j = 0;
        for(int i = 0; i < s.size() && j < t.size(); i ++)
            if(s[i] == t[j]) j ++;
        return j == t.size();
    }
};


int main() {

    return 0;
}
