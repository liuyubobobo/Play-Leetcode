/// Source : https://leetcode.com/problems/complement-of-base-10-integer/
/// Author : liuyubobobo
/// Time   : 2019-03-16

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(logN)
/// Space Complexity: O(logN)
class Solution {
public:
    int bitwiseComplement(int N) {

        if(!N) return 1;

        vector<int> binary;
        while(N) binary.push_back(1 - N % 2), N /= 2;
        reverse(binary.begin(), binary.end());

        int res = 0;
        for(int b: binary) res = res * 2 + b;
        return res;
    }
};


int main() {

    return 0;
}