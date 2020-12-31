/// Source : https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/
/// Author : liuyubobobo
/// Time   : 2020-10-15

#include <iostream>
#include <vector>

using namespace std;


/// Tree DP
/// Time Complexity: O(n^5)
/// Space Complexity: O(n^3)
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {

        vector<vector<int>> g(n);
        for(const vector<int>& e: edges)
            g[e[0] - 1].push_back(e[1] - 1), g[e[1] - 1].push_back(e[0] - 1);

        vector<int> res(n - 1, 0);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));

        dfs(n, g, 0, -1, dp);
        for(int i = 0; i < n; i ++){
            for(int depth = 0; depth < n; depth ++)
                for(int d = 1; d < n; d ++)
                    res[d - 1] += dp[i][depth][d];
        }
        return res;
    }

private:
    void dfs(int n, const vector<vector<int>>& tree, int v, int parent,
             vector<vector<vector<int>>>& dp){

        dp[v][0][0] = 1;

        for(int w: tree[v])
            if(w != parent){

                dfs(n, tree, w, v, dp);

                vector<vector<int>> t(n, vector<int>(n, 0));
                for(int wdepth = 0; wdepth + 1 < n; wdepth ++)
                    for(int wd = wdepth; wd < n; wd ++)
                        if(dp[w][wdepth][wd])
                            for(int vdepth = 0; vdepth + wdepth + 1 < n; vdepth ++)
                                for(int vd = vdepth; vd < n; vd ++)
                                    if(dp[v][vdepth][vd])
                                        t[max(vdepth, wdepth + 1)][max(max(vd, wd), vdepth + wdepth + 1)] += dp[v][vdepth][vd] * dp[w][wdepth][wd];

                for(int depth = 0; depth < n; depth ++)
                    for(int d = 0; d < n; d ++)
                        dp[v][depth][d] += t[depth][d];
            }
    }
};


void print_v(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> edges1 = {{1, 2}, {2, 3}, {2, 4}};
    print_v(Solution().countSubgraphsForEachDiameter(4, edges1));
    // 3, 4, 0

    vector<vector<int>> edges2 = {{1, 2}};
    print_v(Solution().countSubgraphsForEachDiameter(2, edges2));
    // 1

    vector<vector<int>> edges3 = {{1, 2}, {2, 3}};
    print_v(Solution().countSubgraphsForEachDiameter(3, edges3));
    // 2 1

    vector<vector<int>> edges4 = {{1, 3}, {1, 4}, {2, 3}};
    print_v(Solution().countSubgraphsForEachDiameter(4, edges4));
    // 3 2 1

    vector<vector<int>> edges5 = {{1, 4}, {1, 3}, {2, 5}, {2, 6}, {3, 6}, {6, 7}};
    print_v(Solution().countSubgraphsForEachDiameter(7, edges5));
    // 6 7 7 5 2 0

    vector<vector<int>> edges6 = {{1, 4}, {1, 5}, {1, 6}, {2, 3}, {2, 5}};
    print_v(Solution().countSubgraphsForEachDiameter(6, edges6));
    // 5 6 4 3 0

    return 0;
}
