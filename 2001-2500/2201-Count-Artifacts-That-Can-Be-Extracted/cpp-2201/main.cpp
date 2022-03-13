/// Source : https://leetcode.com/problems/count-artifacts-that-can-be-extracted/
/// Author : liuyubobobo
/// Time   : 2022-03-12

#include <iostream>
#include <vector>

using namespace std;


/// 2D Presum
/// Time Complexity: O(n^2 + |dig| + |artifacts|)
/// Space Complexity: O(n^2)
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {

        vector<vector<int>> g(n, vector<int>(n, 1));
        for(const vector<int>& p: dig)
            g[p[0]][p[1]] = 0;

        vector<vector<int>> presum(n + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                presum[i + 1][j + 1] = g[i][j] + presum[i][j + 1] + presum[i + 1][j] - presum[i][j];

        int res = 0;
        for(const vector<int>& p: artifacts){
            int x1 = p[0], y1 = p[1], x2 = p[2], y2 = p[3];
            int sum = presum[x2 + 1][y2 + 1] - presum[x1][y2 + 1] - presum[x2 + 1][y1] + presum[x1][y1];
            res += (sum == 0);
        }
        return res;
    }
};


int main() {

    return 0;
}
