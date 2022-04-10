/// Source : https://leetcode.com/problems/count-numbers-with-unique-digits/
/// Author : liuyubobobo
/// Time   : 2022-04-10

#include <iostream>

using namespace std;


/// Math
/// Time Complexity: O((logn)^2)
/// Space Complexity: O(1)
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {

        int res = 1;
        for(int w = 1; w <= n; w ++){
            int tres = 9, choice = 9;
            for(int i = 1; i < w; i ++) tres *= choice, choice --;
            res += tres;
        }
        return res;
    }
};


int main() {

    return 0;
}
