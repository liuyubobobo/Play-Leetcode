/// Source : https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
/// Author : liuyubobobo
/// Time   : 2022-08-27

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int n = garbage.size();

        vector<vector<int>> g(3, vector<int>(n, 0));
        vector<int> total(3, 0);
        for(int i = 0; i < n; i ++){
            for(char c: garbage[i]){
                if(c == 'M') g[0][i] ++, total[0] ++;
                if(c == 'P') g[1][i] ++, total[1] ++;
                if(c == 'G') g[2][i] ++, total[2] ++;
            }
        }

        int res = 0;
        for(int i = 0; i < 3; i ++)
            res += solve(n, total[i], g[i], travel);
        return res;
    }

private:
    int solve(int n, int total, const vector<int>& g, const vector<int>& travel){

        if(total == 0) return 0;

        int res = g[0];
        total -= g[0];
        for(int i = 1; i < n && total; i ++){
            res += travel[i - 1];
            res += g[i];
            total -= g[i];
        }
        return res;
    }
};


int main() {

    vector<string> garbage2 = {"MMM", "PGM", "GP"};
    vector<int> travel2 = {3, 10};
    cout << Solution().garbageCollection(garbage2, travel2) << '\n';

    return 0;
}
