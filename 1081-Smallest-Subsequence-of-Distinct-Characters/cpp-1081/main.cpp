/// Source : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
/// Author : liuyubobobo
/// Time   : 2020-12-01

#include <iostream>
#include <vector>

using namespace std;


/// Mono Stack
/// Same as 316
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> left(26, 0), used(26, 0);
        for(char c: s) left[c - 'a'] ++;

        string res = "";
        for(char c: s){
            if(!used[c - 'a']){
                while(res != "" && left[res.back() - 'a'] && c <= res.back()){
                    used[res.back() - 'a'] = false ;
                    res.pop_back();
                }
                res += c, used[c - 'a'] = true;
            }
            left[c - 'a'] --;
        }
        return res;
    }
};


int main() {

    return 0;
}
