/// Source : https://leetcode.com/problems/number-complement/
/// Author : liuyubobobo
/// Time   : 2021-10-17

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(logn)
/// Space Complexity: O(logn)
class Solution {
public:
    int findComplement(int num) {

        vector<int> bin;
        while(num){
            bin.push_back(num % 2);
            num /= 2;
        }

        reverse(bin.begin(), bin.end());

        int res = 0;
        for(int e: bin)
            res = res * 2 + (1 - e);
        return res;
    }
};


int main() {

    return 0;
}
