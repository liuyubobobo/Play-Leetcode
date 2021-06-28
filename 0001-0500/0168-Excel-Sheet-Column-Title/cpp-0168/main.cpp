/// Source : https://leetcode.com/problems/excel-sheet-column-title/
/// Author : liuyubobobo
/// Time   : 2021-06-28

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


/// Simulation
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    string convertToTitle(int columnNumber) {

        string res = "";
        while(columnNumber){
            int c = columnNumber % 26;
            if(c == 0) c += 26;

            res += string(1, 'A' + c - 1);
            columnNumber = (columnNumber - c) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {

    cout << Solution().convertToTitle(1) << endl;
    // A

    cout << Solution().convertToTitle(28) << endl;
    // AB

    cout << Solution().convertToTitle(701) << endl;
    // ZY

    cout << Solution().convertToTitle(2147483647) << endl;
    // FXSHRXW

    cout << Solution().convertToTitle(52) << endl;
    // AZ

    return 0;
}
