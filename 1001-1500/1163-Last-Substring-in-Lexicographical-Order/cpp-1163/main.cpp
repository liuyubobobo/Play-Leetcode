/// Source : https://leetcode.com/problems/last-substring-in-lexicographical-order/
/// Author : liuyubobobo
/// Time   : 2019-08-22

#include <iostream>

using namespace std;


/// Two Pointers
/// See here for details:
/// https://leetcode.com/problems/last-substring-in-lexicographical-order/discuss/363662/Short-python-code-O(n)-time-and-O(1)-space-with-proof
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string lastSubstring(string s) {

        int i = 0, j = 1, k = 0;
        while(j + k < s.size()){

            if(s[i + k] == s[j + k]) k ++;
            else if(s[i + k] > s[j + k]) j = j + k + 1, k = 0;
            else i = max(j, i + k + 1), j = i + 1, k = 0;
        }
        return s.substr(i);
    }
};


int main() {

    return 0;
}