/// Source : https://leetcode.com/problems/similar-rgb-color/description/
/// Author : liuyubobobo
/// Time   : 2018-03-17

#include <iostream>
#include <cassert>
#include <sstream>
#include <iomanip>

using namespace std;

/// Brute Force
/// Dealing with each color component seperately
///
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    string similarRGB(string color) {

        int r = stoi(color.substr(1, 2), 0, 16);
        int g = stoi(color.substr(3, 2), 0, 16);
        int b = stoi(color.substr(5, 2), 0, 16);

        return "#" + f(r) + f(g) + f(b);
    }

private:
    string f(int color){

        int res = color / 17 + (color % 17 > 8 ? 1 : 0);

        stringstream ss("#");
        ss << std::hex << setfill('0') << setw(2);
        ss << res * 17;

        return ss.str();
    }
};


int main() {

    cout << Solution().similarRGB("#09f166") << endl;
    cout << Solution().similarRGB("#1c9e03") << endl;

    return 0;
}