/// Source : https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
/// Author : liuyubobobo
/// Time   : 2021-03-13

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        int a = -1, b = -1;
        for(int i = 0; i < s1.size(); i ++)
            if(s1[i] != s2[i]){
                if(a == -1) a = i;
                else if(b == -1) b = i;
                else return false;
            }

        if(a == -1 && b == -1) return true;

        if(a != -1 && b == -1) return false;

        return s1[a] == s2[b] && s1[b] == s2[a];
    }
};


int main() {

    cout << Solution().areAlmostEqual("bank", "kanb") << endl;
    // 1

    cout << Solution().areAlmostEqual("attack", "defend") << endl;
    // 0

    cout << Solution().areAlmostEqual("kelb", "kelb") << endl;
    // 1

    cout << Solution().areAlmostEqual("abcd", "dcba") << endl;
    // 0

    return 0;
}
