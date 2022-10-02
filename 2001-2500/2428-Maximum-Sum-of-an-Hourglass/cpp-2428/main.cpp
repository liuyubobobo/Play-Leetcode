/// Source : https://leetcode.com/problems/maximum-sum-of-an-hourglass/
/// Author : liuyubobobo
/// Time   : 2022-10-01

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(R * C)
/// Space Complexity: O(1)
class Solution {
public:
    int maxSum(vector<vector<int>>& g) {

        int R = g.size(), C = g[0].size(), res = 0;
        for(int i = 0; i + 2 < R; i ++)
            for(int j = 0; j + 2 < C; j ++){
                int t = g[i][j] + g[i][j + 1] + g[i][j + 2] + g[i + 1][j + 1] + g[i + 2][j] + g[i + 2][j + 1] + g[i + 2][j + 2];
                res = max(res, t);
            }
        return res;
    }
};


int main() {

    return 0;
}
