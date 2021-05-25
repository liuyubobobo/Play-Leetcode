/// Source : https://leetcode.com/problems/to-lower-case/
/// Author : liuyubobobo
/// Time   : 2021-05-24

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string toLowerCase(string s) {

        for(char& c: s)
            c = tolower(c);
        return s;
    }
};


int main() {

    return 0;
}
