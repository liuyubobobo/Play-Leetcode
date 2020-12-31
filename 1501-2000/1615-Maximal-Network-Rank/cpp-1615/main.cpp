/// Source : https://leetcode.com/problems/maximal-network-rank/
/// Author : liuyubobobo
/// Time   : 2020-10-10

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Brute Force
/// Time Complexity: O(V^2)
/// Space Complexity: O(V + E)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        vector<unordered_set<int>> g(n);
        for(const vector<int>& e: roads)
            g[e[0]].insert(e[1]), g[e[1]].insert(e[0]);

        int res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++){
                int tres = g[i].size() + g[j].size();
                if(g[i].count(j)) tres --;
                res = max(res, tres);
            }
        return res;
    }
};


int main() {

    vector<vector<int>> roads1 = {{0,1},{0,3},{1,2},{1,3}};
    cout << Solution().maximalNetworkRank(4, roads1) << endl;
    // 4

    vector<vector<int>> roads2 = {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}};
    cout << Solution().maximalNetworkRank(5, roads2) << endl;
    // 5

    vector<vector<int>> roads3 = {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}};
    cout << Solution().maximalNetworkRank(8, roads3) << endl;
    // 5

    return 0;
}
