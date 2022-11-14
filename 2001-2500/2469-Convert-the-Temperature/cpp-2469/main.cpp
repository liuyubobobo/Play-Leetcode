/// Source : https://leetcode.com/problems/convert-the-temperature/
/// Author : liuyubobobo
/// Time   : 2022-11-12

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    vector<double> convertTemperature(double celsius) {

        double k = celsius + 273.15;
        double f = celsius * 1.80 + 32.00;
        return {k, f};
    }
};


int main() {

    return 0;
}
