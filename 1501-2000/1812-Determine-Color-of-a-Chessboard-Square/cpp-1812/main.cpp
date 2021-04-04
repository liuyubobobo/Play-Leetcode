/// Source : https://leetcode.com/problems/determine-color-of-a-chessboard-square/
/// Author : liuyubobobo
/// Time   : 2021-04-04

#include <iostream>

using namespace std;


/// Mathematics
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    bool squareIsWhite(string coordinates) {

        int a = coordinates[0] - 'a', b = coordinates[1] - '1';
        return (a + b) % 2;
    }
};


int main() {

    return 0;
}
