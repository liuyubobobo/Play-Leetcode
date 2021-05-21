/// Source : https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
/// Author : liuyubobobo
/// Time   : 2021-05-08

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;


/// DAG DP
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

        int res = -1;
        for(char color = 'a'; color <= 'z'; color ++){
            int tres = solve(n, g, degrees, color, colors);
            if(tres == -1) return -1;
            res = max(res, tres);
        }
        return res;
    }

private:
    int solve(int n, const vector<set<int>>& g, vector<int> degrees, char color, const string& colors){

        queue<int> q;
        vector<int> dp(n, 0);
        int cnt = n;
        for(int u = 0; u < n; u ++)
            if(degrees[u] == 0){
                q.push(u);
                cnt --;
                if(colors[u] == color)
                    dp[u] = 1;
            }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v: g[u]){
                dp[v] = max(dp[v], dp[u] + (colors[v] == color));
                degrees[v] --;
                if(degrees[v] == 0)
                    cnt --, q.push(v);
            }
        }

        if(cnt) return -1;
        return *max_element(dp.begin(), dp.end());
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
