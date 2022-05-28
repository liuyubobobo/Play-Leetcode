/// Source : https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/
/// Author : liuyubobobo
/// Time   : 2021-05-28

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool digitCount(string num) {

        vector<int> f(10, 0);
        for(char c: num) f[c - '0'] ++;

        for(int i = 0; i < num.size(); i ++)
            if(num[i] - '0' != f[i]) return false;
        return true;
    }
};


int main() {

    return 0;
}
