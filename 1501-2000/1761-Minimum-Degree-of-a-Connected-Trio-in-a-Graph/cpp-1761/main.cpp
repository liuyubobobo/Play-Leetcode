/// Source : https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/
/// Author : liuyubobobo
/// Time   : 2021-02-13

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {

        vector<vector<bool>> table(n, vector<bool>(n, false));
        vector<int> degree(n, 0);
        for(const vector<int>& e: edges){
            table[e[0] - 1][e[1] - 1] = table[e[1] - 1][e[0] - 1] = 1;
            degree[e[0] - 1] ++;
            degree[e[1] - 1] ++;
        }

        int res = INT_MAX;
        for(int u = 0; u < n; u ++)
            for(int v = u + 1; v < n; v ++)
                if(table[u][v])
                    for(int w = v + 1; w < n; w ++)
                        if(table[u][w] && table[v][w])
                            res = min(res, degree[u] + degree[v] + degree[w] - 6);
        return res == INT_MAX ? -1 : res;
    }
};


int main() {

    vector<vector<int>> edges1 = {
            {1,2},{1,3},{3,2},{4,1},{5,2},{3,6}
    };
    cout << Solution().minTrioDegree(6, edges1) << endl;
    // 3

    vector<vector<int>> edges2 = {
            {1,3},{4,1},{4,3},{2,5},{5,6},{6,7},{7,5},{2,6}
    };
    cout << Solution().minTrioDegree(7, edges2) << endl;
    // 0

    return 0;
}
