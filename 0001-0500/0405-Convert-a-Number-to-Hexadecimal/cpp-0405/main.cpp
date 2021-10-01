/// Source : https://leetcode.com/problems/convert-a-number-to-hexadecimal/
/// Author : liuyubobobo
/// Time   : 2021-10-01

#include <iostream>
#include <sstream>

using namespace std;


/// Std
/// Time Complexity: O(log(num))
/// Space Complexity: O(1)
class Solution {
public:
    string toHex(int num) {

        stringstream ss;

        ss << hex << num;
        return ss.str();
    }
};


int main() {

    return 0;
}
