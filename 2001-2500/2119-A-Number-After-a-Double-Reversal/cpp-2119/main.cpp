/// Source : https://leetcode.com/problems/a-number-after-a-double-reversal/
/// Author : liuyubobobo
/// Time   : 2021-12-25

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    bool isSameAfterReversals(int num) {

        if(num == 0) return true;
        return num % 10 != 0;
    }
};


int main() {

    return 0;
}
