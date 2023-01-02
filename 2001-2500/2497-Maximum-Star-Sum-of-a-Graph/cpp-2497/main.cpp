/// Source : https://leetcode.com/problems/maximum-star-sum-of-a-graph/description/
/// Author : liuyubobobo
/// Time   : 2022-12-31

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Brute Force
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {

        int n = vals.size();
        vector<vector<int>> g(n);
        for(const vector<int>& e: edges){
            int a = e[0], b = e[1];
            g[a].push_back(vals[b]);
            g[b].push_back(vals[a]);
        }

        for(vector<int>& v: g) sort(v.begin(), v.end(), greater<int>());

        int res = INT_MIN;
        for(int u = 0; u < n; u ++){
            int sum = vals[u];
            for(int i = 0; i < g[u].size() && i < k && g[u][i] > 0; i ++) sum += g[u][i];
            res = max(res, sum);
        }
        return res;
    }
};


int main() {

    return 0;
}
