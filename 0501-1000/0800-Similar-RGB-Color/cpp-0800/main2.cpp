/// Source : https://leetcode.com/problems/similar-rgb-color/description/
/// Author : liuyubobobo
/// Time   : 2018-03-17

#include <iostream>
#include <cassert>
#include <sstream>
#include <iomanip>

using namespace std;

/// Brute Force
/// Using std to handle hex based number and string
///
/// Time Complexity: O(16*16*16*6)
/// Space Complexity: O(1)
class Solution {
public:
    string similarRGB(string color) {

        int color_r = stoi(color.substr(1, 2), 0, 16);
        int color_g = stoi(color.substr(3, 2), 0, 16);
        int color_b = stoi(color.substr(5, 2), 0, 16);

        string res = "";
        int best = INT_MAX;
        for(int r = 0 ; r < 16 ; r ++)
            for(int g = 0 ; g < 16 ; g ++)
                for(int b = 0 ; b < 16 ; b ++){
                    int diff = get_diff(color_r, color_g, color_b, r * 16 + r, g * 16 + g, b * 16 + b);
                    if(diff < best){
                        best = diff;
                        res = get_hex_string(r * 16 + r, g * 16 + g, b * 16 + b);
                    }
                }
        return res;
    }

private:
    int get_diff(int r1, int g1, int b1, int r2, int g2, int b2){

        int r_diff = (r1 - r2) * (r1 - r2);
        int g_diff = (g1 - g2) * (g1 - g2);
        int b_diff = (b1 - b2) * (b1 - b2);
        return r_diff + g_diff + b_diff;
    }

    string get_hex_string(int r, int g, int b){

        stringstream ss("#");
        ss << std::hex << setfill('0') << setw(2);
        ss << r;

        ss << std::hex << setfill('0') << setw(2);
        ss << g;

        ss << std::hex << setfill('0') << setw(2);
        ss << b;

        return "#" + ss.str();
    }
};


int main() {

    cout << Solution().similarRGB("#09f166") << endl;
    cout << Solution().similarRGB("#1c9e03") << endl;

    return 0;
}