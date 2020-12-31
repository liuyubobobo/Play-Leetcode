/// Source : https://leetcode.com/problems/minimum-window-substring/
/// Author : liuyubobobo
/// Time   : 2017-01-17

#include <iostream>
#include <cassert>

using namespace std;

/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string minWindow(string s, string t) {

        int tFreq[256] = {0};
        for(int i = 0 ; i < t.size() ; i ++)
            tFreq[t[i]] ++;

        int sFreq[256] = {0};
        int sCnt = 0;

        int minLength = s.size() + 1;
        int startIndex = -1;

        int l = 0, r = -1;
        while(l < s.size()){

            if(r + 1 < s.size() && sCnt < t.size()){

                sFreq[s[r+1]] ++;
                if(sFreq[s[r+1]] <= tFreq[s[r+1]])
                    sCnt ++;
                r ++;
            }
            else{
                assert(sCnt <= t.size());
                if(sCnt == t.size() && r - l + 1 < minLength){
                    minLength = r - l + 1;
                    startIndex = l;
                }

                sFreq[s[l]] --;
                if(sFreq[s[l]] < tFreq[s[l]])
                    sCnt --;
                l ++;
            }
        }

        if( startIndex != -1 )
            return s.substr(startIndex, minLength);

        return "";
    }
};

int main() {

    cout << Solution().minWindow("ADOBECODEBANC", "ABC") << endl;
    // BANC

    cout << Solution().minWindow("a", "aa") << endl;
    // empty

    cout << Solution().minWindow("aa", "aa") << endl;
    // aa

    cout << Solution().minWindow("bba", "ab") << endl;
    // ba

    return 0;
}