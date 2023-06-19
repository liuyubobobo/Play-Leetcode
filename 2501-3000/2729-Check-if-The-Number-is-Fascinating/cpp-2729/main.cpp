/// Source : https://leetcode.com/problems/check-if-the-number-is-fascinating/description/
/// Author : liuyubobobo
/// Time   : 2023-06-13

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


/// Simulation
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    bool isFascinating(int n) {

        int a = n, b = 2 * n, c = 3 * n;
        string s = to_string(a) + to_string(b) + to_string(c);

        vector<int> f(10, 0);
        for(char c: s) f[c - '0'] ++;
        return count_if(f.begin() + 1, f.end(), [](int e){return e == 1;}) == 9;
    }
};


int main() {

    return 0;
}
