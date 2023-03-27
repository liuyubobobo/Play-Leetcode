/// Source : https://leetcode.com/problems/number-of-even-and-odd-bits/description/
/// Author : liuyubobobo
/// Time   : 2023-03-25

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(log(n))
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> evenOddBit(int n) {

        int even = 0, odd = 0;
        for(int p = 0; p < 10; p ++){
            if((n >> p) & 1){
                if(p & 1) odd ++; else even ++;
            }
        }
        return {even, odd};
    }
};


int main() {

    return 0;
}
