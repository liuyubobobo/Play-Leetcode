/// Source : https://leetcode.com/problems/minimum-window-substring/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <cassert>
#include <unordered_set>
#include <vector>

using namespace std;

/// Sliding Window
/// Using filtered s, which remove all characters not in T
/// will be a good improvement when T is small and lots of character are not in S:)
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string minWindow(string s, string t) {

        unordered_set<char> t_set;
        int tFreq[256] = {0};
        for(char c: t){
            t_set.insert(c);
            tFreq[c] ++;
        }

        string filtered_s = "";
        vector<int> pos;
        for(int i = 0; i < s.size() ; i ++)
            if(t_set.find(s[i]) != t_set.end()){
                filtered_s += s[i];
                pos.push_back(i);
            }


        int sFreq[256] = {0};
        int sCnt = 0;

        int minLength = s.size() + 1;
        int startIndex = -1;

        int l = 0, r = -1;
        while(l < filtered_s.size()){

            if(r + 1 < filtered_s.size() && sCnt < t.size()){

                sFreq[filtered_s[r+1]] ++;
                if(sFreq[filtered_s[r+1]] <= tFreq[filtered_s[r+1]])
                    sCnt ++;
                r ++;
            }
            else{
                assert(sCnt <= t.size());
                if(sCnt == t.size() && pos[r] - pos[l] + 1 < minLength){
                    minLength = pos[r] - pos[l] + 1;
                    startIndex = pos[l];
                }

                sFreq[filtered_s[l]] --;
                if(sFreq[filtered_s[l]] < tFreq[filtered_s[l]])
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