/// Source : https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
/// Author : liuyubobobo
/// Time   : 2021-05-20

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;


/// DAG DP
/// Another implementation
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {

        int n = colors.size();
        vector<set<int>> g(n);
        for(const vector<int>& e: edges)
            g[e[0]].insert(e[1]);

        vector<int> degrees(n, 0);
        for(int u = 0; u < n; u ++)
            for(int v: g[u]) degrees[v] ++;

        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        int cnt = n;
        for(int u = 0; u < n; u ++)
            if(degrees[u] == 0){
                q.push(u);
                cnt --;
                dp[u][colors[u] - 'a'] = 1;
            }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v: g[u]){
                for(int color = 0; color < 26; color ++)
                    dp[v][color] = max(dp[v][color], dp[u][color] + (colors[v] == 'a' + color));
                degrees[v] --;
                if(degrees[v] == 0)
                    cnt --, q.push(v);
            }
        }

        if(cnt) return -1;

        int res = 0;
        for(int i = 0; i < n; i ++)
            res = max(res, *max_element(dp[i].begin(), dp[i].end()));
        return res;
    }
};


int main() {

    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};
    cout << Solution().largestPathValue("abaca", edges1) << endl;
    // 3

    vector<vector<int>> edges2 = {{0, 0}};
    cout << Solution().largestPathValue("a", edges2) << endl;
    // -1

    return 0;
}
