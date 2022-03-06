/// Source : https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/
/// Author : liuyubobobo
/// Time   : 2022-03-05

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: ((c2 - c1) * (r2 - r1)
/// Space Complexity: O(1)
class Solution {
public:
    vector<string> cellsInRange(string s) {

        char c1 = s[0], c2 = s[3];
        char r1 = s[1], r2 = s[4];

        vector<string> res;
        for(char c = c1; c <= c2; c ++)
            for(char r = r1; r <= r2; r ++){
                string t = "";
                t += c, t += r;
                res.push_back(t);
            }
        return res;
    }
};


int main() {

    return 0;
}
