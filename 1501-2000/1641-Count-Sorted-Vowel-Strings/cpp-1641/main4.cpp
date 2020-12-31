/// Source : https://leetcode.com/problems/count-sorted-vowel-strings/
/// Author : liuyubobobo
/// Time   : 2020-11-01

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Math
/// Tiime Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};


int main() {

    cout << Solution().countVowelStrings(1) << endl;
    // 5

    cout << Solution().countVowelStrings(2) << endl;
    // 15

    cout << Solution().countVowelStrings(33) << endl;
    // 66045

    cout << Solution().countVowelStrings(50) << endl;
    // 316251

    return 0;
}
