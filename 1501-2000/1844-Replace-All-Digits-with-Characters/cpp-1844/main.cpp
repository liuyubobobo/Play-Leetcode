/// Source : https://leetcode.com/problems/replace-all-digits-with-characters/
/// Author : liuyubobobo
/// Time   : 2021-05-01

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string replaceDigits(string s) {

        for(int i = 1; i < s.size(); i += 2)
            s[i] = s[i - 1] + (s[i] - '0');
        return s;
    }
};


int main() {

    return 0;
}
