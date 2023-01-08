/// Source : https://leetcode.com/problems/categorize-box-according-to-criteria/description/
/// Author : liuyubobobo
/// Time   : 2023-01-07

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    string categorizeBox(long long length, long long width, long long height, long long mass) {

        bool is_bulky = false;
        if(length >= 10000 || width >= 10000 || height >= 10000 || mass >= 10000)
            is_bulky = true;

        long long volume = length * width * height;
        if(volume >= 1000000000) is_bulky = true;

        bool is_heavy = mass >= 100;

        if(is_bulky && is_heavy) return "Both";
        if(!is_bulky && !is_heavy) return "Neither";
        return is_bulky ? "Bulky" : "Heavy";
    }
};


int main() {

    return 0;
}
