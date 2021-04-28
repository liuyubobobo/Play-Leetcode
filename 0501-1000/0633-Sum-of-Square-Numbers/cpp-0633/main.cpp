/// Source : https://leetcode.com/problems/sum-of-square-numbers/
/// Author : liuyubobobo
/// Time   : 2021-04-28

#include <iostream>
#include <unordered_set>

using namespace std;


/// Brute Force
/// Time Complexity: O(sqrt(c))
/// Space Complexity: O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {

        for(int i = 0; i * i <= c - i * i; i ++){
            int x = (int)sqrt(c - i * i);
            if(i * i + x * x == c) return true;
        }
        return false;
    }
};


int main() {

    return 0;
}
