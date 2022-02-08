/// Source : https://leetcode.com/problems/add-digits/
/// Author : liuyubobobo
/// Time   : 2022-02-07

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O((logn)^2)
/// Space Complexity: O(1)
class Solution {
public:
    int addDigits(int num) {
        while(num >= 10)
            num = digit_sum(num);
        return num;
    }

private:
    int digit_sum(int num){
        int res = 0;
        while(num) res += num % 10, num /= 10;
        return res;
    }
};


int main() {

    return 0;
}
