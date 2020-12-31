/// Source : https://leetcode.com/problems/clumsy-factorial/
/// Author : liuyubobobo
/// Time   : 2019-03-09

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int clumsy(int N) {

        if(N == 1) return 1;
        if(N == 2) return 2;
        if(N == 3) return 6;

        int res = N * (N - 1) / (N - 2);
        N -= 3;
        while(N >= 4){
            res += N - (N - 1) * (N - 2) / (N - 3);
            N -= 4;
        }
        return res + !!N;
    }
};


int main() {

    cout << Solution().clumsy(4) << endl;
    cout << Solution().clumsy(10) << endl;

    return 0;
}