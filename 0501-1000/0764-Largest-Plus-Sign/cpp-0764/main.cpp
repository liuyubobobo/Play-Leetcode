/// Source : https://leetcode.com/problems/largest-plus-sign/
/// Author : liuyubobobo
/// Time   : 2021-09-09

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {

        vector<vector<int>> g(n, vector<int>(n, 1));
        for(const vector<int>& mine: mines)
            g[mine[0]][mine[1]] = 0;

        vector<vector<int>> top(n, vector<int>(n, 0));
        top[0] = g[0];
        for(int i = 1; i < n; i ++)
            for(int j = 0; j < n; j ++)
                if(g[i][j]) top[i][j] = top[i - 1][j] + 1;

        vector<vector<int>> bottom(n, vector<int>(n, 0));
        bottom[n - 1] = g[n - 1];
        for(int i = n - 2; i >= 0; i --)
            for(int j = 0; j < n; j ++)
                if(g[i][j]) bottom[i][j] = bottom[i + 1][j] + 1;

        vector<vector<int>> left(n, vector<int>(n, 0));
        for(int i = 0; i < n; i ++) left[i][0] = g[i][0];
        for(int j = 1; j < n; j ++)
            for(int i = 0; i < n; i ++)
                if(g[i][j]) left[i][j] = left[i][j - 1] + 1;

        vector<vector<int>> right(n, vector<int>(n, 0));
        for(int i = 0; i < n; i ++) right[i][n - 1] = g[i][n - 1];
        for(int j = n - 2; j >= 0; j --)
            for(int i = 0; i < n; i ++)
                if(g[i][j]) right[i][j] = right[i][j + 1] + 1;

        int res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                if(g[i][j]){
                    int a = top[i][j], b = bottom[i][j], c = left[i][j], d = right[i][j];
                    res = max(res, min(min(a, b), min(c, d)));
                }
        return res;
    }
};


int main() {

    return 0;
}
