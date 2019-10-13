/// Source : https://leetcode.com/problems/split-a-string-in-balanced-strings/
/// Author : liuyubobobo
/// Time   : 2019-10-12

#include <iostream>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int balancedStringSplit(string s) {

        int l = 0, r = 0, res = 0;
        for(char c: s){
            if(c == 'L') l ++;
            else r ++;

            if(l == r) res ++, l = r = 0;
        }
        return res;
    }
};


int main() {

    cout << Solution().balancedStringSplit("RLRRLLRLRL") << endl;
    // 4

    cout << Solution().balancedStringSplit("RLLLLRRRLR") << endl;
    // 3

    return 0;
}