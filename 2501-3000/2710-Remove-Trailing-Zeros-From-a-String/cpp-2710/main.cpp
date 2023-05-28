/// Source : https://leetcode.com/problems/remove-trailing-zeros-from-a-string/description/
/// Author : liuyubobobo
/// Time   : 2023-05-27

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(|num|)
/// Space Complexity: O(|num|)
class Solution {
public:
    string removeTrailingZeros(string num) {

        while(!num.empty() && num.back() == '0') num.pop_back();
        return num;
    }
};


int main() {

    return 0;
}
