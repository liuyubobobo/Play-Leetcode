/// Source : https://leetcode.com/problems/pass-the-pillow/description/
/// Author : liuyubobobo
/// Time   : 2023-03-04

#include <iostream>

using namespace std;


/// Math
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int passThePillow(int n, int time) {

        int k = 2 * (n - 1);
        time %= k;

        if(time <= n - 1) return time + 1;

        time -= (n - 1);
        return n - time;
    }
};


int main() {

    return 0;
}
