/// Source : https://leetcode.com/problems/zigzag-conversion/
/// Author : liuyubobobo
/// Time   : 2022-02-28

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(|s|)
/// Space Complexity: O(numRows * |s|)
class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) return s;

        int n = s.size();

        vector<string> res(numRows, string(n, '-'));
        int index = 0, cury = 0;
        while(index < n){
            for(int k = 0; k < numRows && index < n; k ++)
                res[k][cury] = s[index ++];
            if(index >= n) break;

            for(int k = numRows - 2, y = cury + 1; k > 0 && index < n; k --, y ++)
                res[k][y] = s[index ++];
            if(index >= n) break;

            cury += (numRows - 1);
        }

        string ret = "";
        for(int i = 0; i < numRows; i ++)
            for(char c: res[i]) if(c != '-') ret += c;
        return ret;
    }
};


int main() {

    cout << Solution().convert("PAYPALISHIRING", 3) << endl;
    // "PAHNAPLSIIGYIR"

    return 0;
}
