/// Source : https://leetcode.com/problems/bulb-switcher/description/
/// Author : liuyubobobo
/// Time   : 2017-12-01

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

/// Only square number have odd divisor number!
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {

public:
    int bulbSwitch(int n) {
        assert(n >= 0);
        return (int)sqrt(n);
    }
};

int main() {

    cout << Solution().bulbSwitch(2) << endl;
    cout << Solution().bulbSwitch(3) << endl;

    return 0;
}