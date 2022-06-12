/// Source : https://leetcode.com/problems/calculate-amount-paid-in-taxes/
/// Author : liuyubobobo
/// Time   : 2022-06-11

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {

        if(income <= brackets[0][0]){
            return income * brackets[0][1] / (double)100.0;
        }

        int left = income - brackets[0][0];
        double res = brackets[0][0] * brackets[0][1] / (double)100.0;
        for(int i = 1; i < brackets.size() && left; i ++){
            int x = brackets[i][0] - brackets[i - 1][0];
            int t = min(x, left);
            left -= t;
            res += t * brackets[i][1] / (double)100.0;
        }
        return res;
    }
};


int main() {

    vector<vector<int>> br1 = {{3, 50}, {7, 10}, {12, 25}};
    cout << Solution().calculateTax(br1, 10) << '\n';

    return 0;
}
