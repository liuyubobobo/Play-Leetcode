/// Source : https://leetcode.com/problems/similar-rgb-color/description/
/// Author : liuyubobobo
/// Time   : 2018-03-17

#include <iostream>
#include <cassert>

using namespace std;

/// Brute Force
/// Time Complexity: O(16*16*16*6)
/// Space Complexity: O(1)
class Solution {
public:
    string similarRGB(string color) {

        string color_s = "0123456789abcdef";
        string res = "#######";
        int best = INT_MAX;
        for(char c1: color_s)
            for(char c2: color_s)
                for(char c3: color_s){
                    int diff = get_diff(color, c1, c2, c3);
                    if(diff < best){
                        best = diff;
                        res[1] = c1;
                        res[2] = c1;
                        res[3] = c2;
                        res[4] = c2;
                        res[5] = c3;
                        res[6] = c3;
                    }
                }
        return res;
    }

private:
    int get_diff(const string& color, char c1, char c2, char c3){

        int r_diff = get_hex(color[1], color[2]) - get_hex(c1, c1);
        int g_diff = get_hex(color[3], color[4]) - get_hex(c2, c2);
        int b_diff = get_hex(color[5], color[6]) - get_hex(c3, c3);
        return r_diff * r_diff + g_diff * g_diff + b_diff * b_diff;
    }

    int get_hex(char x, char y){
        return get_hex(x) * 16 + get_hex(y);
    }

    int get_hex(char x){
        if(x >= '0' && x <= '9')
            return x - '0';

        assert(x >= 'a' && x <= 'f');
        return 10 + (x - 'a');
    }
};


int main() {
    cout << Solution().similarRGB("#09f166") << endl;
    return 0;
}