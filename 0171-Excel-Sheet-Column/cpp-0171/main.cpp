/// Source : https://leetcode.com/problems/excel-sheet-column-number/description/
/// Author : liuyubobobo
/// Time   : 2018-08-30

#include <iostream>
#include <cmath>

using namespace std;


/// 26-based number
/// Time Complexity: O(len(s))
/// Space Complexity: O(1)
class Solution {
public:
    int titleToNumber(string s) {

        int num = 0;
        for(char c: s)
            num = num * 26 + (c - 'A' + 1);

        return num;
    }
};


int main() {

    cout << Solution().titleToNumber("A") << endl;  // 1
    cout << Solution().titleToNumber("AB") << endl; // 28
    cout << Solution().titleToNumber("ZY") << endl; // 701

    return 0;
}