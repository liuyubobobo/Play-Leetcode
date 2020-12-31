/// Source : https://leetcode.com/problems/remove-duplicate-letters/
/// Author : liuyubobobo
/// Time   : 2020-12-01

#include <iostream>
#include <vector>

using namespace std;


/// Mono Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string removeDuplicateLetters(string s) {

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

    cout << Solution().removeDuplicateLetters("bcabc") << endl;
    // abc

    cout << Solution().removeDuplicateLetters("cbacdcbc") << endl;
    // acdb

    cout << Solution().removeDuplicateLetters("cdadabcc") << endl;
    // adbc

    cout << Solution().removeDuplicateLetters("ccacbaba") << endl;
    // acb

    cout << Solution().removeDuplicateLetters("abacb") << endl;
    // abc

    return 0;
}
