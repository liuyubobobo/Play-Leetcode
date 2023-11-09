/// Source : https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/
/// Author : liuyubobobo
/// Time   : 2023-11-09

#include <iostream>

using namespace std;


/// Math
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

        int a = abs(sx - fx), b = abs(sy - fy);
        int d = max(a, b);
        if(d == 0) return t != 1;
        return t >= d;
    }
};


int main() {

    return 0;
}
