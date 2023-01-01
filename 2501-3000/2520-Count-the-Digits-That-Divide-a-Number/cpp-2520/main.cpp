/// Source : https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/
/// Author : liuyubobobo
/// Time   : 2022-12-31

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(log(num))
/// Space Complexity: O(log(num))
class Solution {
public:
    int countDigits(int num) {

        int res = 0;

        string num_str = to_string(num);
        for(char c: num_str)
            res += num % (c - '0') == 0;
        return res;
    }
};


int main() {

    return 0;
}
