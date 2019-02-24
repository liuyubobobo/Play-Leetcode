/// Source : https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
/// Author : liuyubobobo
/// Time   : 2019-02-23

#include <iostream>
#include <unordered_map>
#include <cassert>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {

        if(!k) return 0;

        int l = 0, r = -1, res = 0;
        unordered_map<char, int> freq;
        while(r + 1 < s.size()){

            while(r + 1 < s.size() && ok(freq, s[r + 1], k))
                freq[s[r + 1]] ++, r ++;
            // assert(freq.size() == k);
            res = max(res, r - l + 1);

            while(l <= r && freq.size() >= k){
                freq[s[l]] --;
                if(freq[s[l]] == 0) freq.erase(s[l]);
                l ++;
            }
        }
        return res;
    }

private:
    bool ok(const unordered_map<char, int>& freq, char c, int k){

        if(freq.size() <= k - 1) return true;

        assert(freq.size() == k);
        return freq.count(c);
    }
};


int main() {

    return 0;
}