/// Source : https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
/// Author : liuyubobobo
/// Time   : 2019-02-23

#include <iostream>
#include <unordered_map>
#include <cassert>

using namespace std;


/// Sliding Window (Another implement version)
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {

        if(!k) return 0;

        int l = 0, r = -1, res = 0;
        unordered_map<char, int> freq;
        while(r + 1 < s.size()){

            if(freq.size() < k || freq.count(s[r + 1]))
                freq[s[r + 1]] ++, r ++;
            else{
                freq[s[l]] --;
                if(freq[s[l]] == 0) freq.erase(s[l]);
                l ++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};


int main() {

    return 0;
}