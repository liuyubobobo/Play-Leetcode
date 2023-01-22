/// Source : https://leetcode.com/problems/alternating-digit-sum/description/
/// Author : liuyubobobo
/// Time   : 2023-01-21

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(logn)
/// Space Complexity: O(logn)
class Solution {
public:
    int alternateDigitSum(int n) {

        string s = to_string(n);
        int res = 0;
        for(int i = 0; i < s.size(); i ++)
            res += (i % 2 ? -1 : 1) * (s[i] - '0');
        return res;
    }
};


int main() {

    return 0;
}
