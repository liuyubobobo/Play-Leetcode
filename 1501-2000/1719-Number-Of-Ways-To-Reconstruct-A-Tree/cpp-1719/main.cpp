/// Source : https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/
/// Author : liuyubobobo
/// Time   : 2021-01-16

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


/// Greedy and DFS
/// Time Complexity: O(V^2 + E)
/// Space Complexity: O(V + E)
class Solution {

public:
    int checkWays(vector<vector<int>>& pairs) {

        unordered_map<int, unordered_set<int>> g;
        int n = 0;
        for(const vector<int>& e: pairs)
            g[e[0] - 1].insert(e[1] - 1),
                    g[e[1] - 1].insert(e[0] - 1),
                    n = max(n, max(e[0], e[1]));

        vector<int> degree(n, 0);
        int maxdegree = 0, maxdegv;
        for(const pair<int, unordered_set<int>>& p: g){
            degree[p.first] = p.second.size();
            if(degree[p.first] > maxdegree)
                maxdegree = degree[p.first], maxdegv = p.first;
        }

        if(maxdegree != (int)g.size() - 1) return 0;
        vector<bool> visited(n, false);
        int ccnum = 0;
        return dfs(g, maxdegv, degree, visited, ccnum);
    }

private:
    int dfs(unordered_map<int, unordered_set<int>>& g, int u,
            vector<int>& degree, vector<bool>& visited, int& ccnum){

        visited[u] = true;

        int udegree = degree[u];

        vector<int> next(g.at(u).begin(), g.at(u).end());

        int ans = 1;
        for(int v: next){
            if(degree[v] == udegree) ans = 2;
            g[u].erase(v), g[v].erase(u);
            degree[u] --;
            degree[v] --;
        }

        sort(next.begin(), next.end(), [&](int p, int q){return degree[p] > degree[q];});
        for(int v: next)
            if(!visited[v]){
                int tnum = 0;
                int tans = dfs(g, v, degree, visited, tnum);
                ccnum += tnum;
                if(tans == 0) return 0;
                ans = max(ans, tans);
            }
        ccnum += 1;
        if(udegree != ccnum - 1) return 0;
        return ans;
    }
};


int main() {

    vector<vector<int>> pairs1 = {{1, 2}, {2, 3}};
    cout << Solution().checkWays(pairs1) << endl;
    // 1

    vector<vector<int>> pairs2 = {{1, 2}, {2, 3}, {1, 3}};
    cout << Solution().checkWays(pairs2) << endl;
    // 2

    vector<vector<int>> pairs3 = {{1, 2}, {2, 3}, {2, 4}, {1, 5}};
    cout << Solution().checkWays(pairs3) << endl;
    // 0

    vector<vector<int>> pairs4 = {{3, 5}, {4, 5}, {2, 5}, {1, 5}, {1, 4}, {2, 4}};
    cout << Solution().checkWays(pairs4) << endl;
    // 1

    vector<vector<int>> pairs5 = {{5, 7}, {11, 12}, {2, 9}, {8, 10}, {1, 4}, {3, 6}};
    cout << Solution().checkWays(pairs5) << endl;
    // 0

    vector<vector<int>> pairs6 = {{4, 5}, {3, 4}, {2, 4}};
    cout << Solution().checkWays(pairs6) << endl;
    // 1

    vector<vector<int>> pairs7 = {{1, 5}, {1, 3}, {2, 3}, {2, 4}, {3, 5}, {3, 4}};
    cout << Solution().checkWays(pairs7) << endl;
    // 2

    return 0;
}
