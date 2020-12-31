/// Source : https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
/// Author : liuyubobobo
/// Time   : 2017-11-10

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

/// Sliding Window
/// Time Complexity: O(len(p) + len(s))
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;
        if(s.size() < p.size())
            return res;

        assert(p.size() > 0);

        vector<int> freq_p(26, 0);
        for(char c: p)
            freq_p[c - 'a'] += 1;

        vector<int> freq_s(26, 0);
        int l = 0, r = -1; // Sliding window: s[l, r]
        while(r + 1 < s.size()){
            r ++;
            freq_s[s[r] - 'a'] ++;
            if(r - l + 1 > p.size())
                freq_s[s[l++] - 'a'] --;

            if(r - l + 1 == p.size() && same(freq_s, freq_p))
                res.push_back(l);
        }

        return res;
    }

private:
    bool same(const vector<int>& freq_s, const vector<int>& freq_p){
        for(int i = 0 ; i < 26; i ++)
            if(freq_s[i] != freq_p[i])
                return false;
        return true;
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    string s1 = "cbaebabacd";
    string p1 = "abc";
    printVec(Solution().findAnagrams(s1, p1));
    // [0, 6]

    // ---

    string s2 = "abab";
    string p2 = "ab";
    printVec(Solution().findAnagrams(s2, p2));

    return 0;
}