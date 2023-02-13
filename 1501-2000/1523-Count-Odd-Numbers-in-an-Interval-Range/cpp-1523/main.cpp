/// Source : https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/
/// Author : liuyubobobo
/// Time   : 2023-02-13

#include <iostream>

using namespace std;


/// Math
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int countOdds(int low, int high) {

        int len = high - low + 1;
        return low % 2 == 1 ? (len + 1) / 2 : len / 2;
    }
};


int main() {

    return 0;
}
