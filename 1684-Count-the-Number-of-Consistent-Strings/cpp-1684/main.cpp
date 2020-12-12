/// Source : https://leetcode.com/problems/count-the-number-of-consistent-strings/
/// Author : liuyubobobo
/// Time   : 2020-12-12

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * len)
/// Space Complexity: O(1)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        vector<bool> ok(26, false);
        for(char c: allowed) ok[c - 'a'] = true;

        int res = 0;
        for(const string& s: words){

            for(char c: s)
                if(!ok[c - 'a']){
                    res ++;
                    break;
                }
        }
        return words.size() - res;
    }
};


int main() {

    string allowed1 = "ab";
    vector<string> words1 = {"ad","bd","aaab","baa","badab"};
    cout << Solution().countConsistentStrings(allowed1, words1) << endl;
    // 2

    return 0;
}
