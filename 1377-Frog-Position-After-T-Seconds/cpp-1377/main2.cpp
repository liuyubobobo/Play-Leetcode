/// Source : https://leetcode.com/problems/frog-position-after-t-seconds/
/// Author : liuyubobobo
/// Time   : 2020-03-14

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// DFS directly
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {

        if(n == 1) return 1.0;

        vector<set<int>> g(n, set<int>());
        for(const vector<int>& e: edges)
            g[e[0] - 1].insert(e[1] - 1), g[e[1] - 1].insert(e[0] - 1);

        target --;
        return dfs(g, 0, -1, target, t);
    }

private:
    double dfs(const vector<set<int>>& g, int cur, int parent, int target, int t){

        if(g[cur].size() == 1 && *g[cur].begin() == parent)
            return cur == target;

        if(cur == target) return t == 0;

        if(t == 0) return 0;

        double res = 0.0;
        for(int next: g[cur])
            if(next != parent){
                res += (1.0 / (g[cur].size() - (parent != -1))) * dfs(g, next, cur, target, t - 1);
            }
        return res;
    }
};


int main() {

    vector<vector<int>> edges1 = {
            {1,2},{1,3},{1,7},{2,4},{2,6},{3,5}
    };
    cout << Solution().frogPosition(7, edges1, 2, 4) << endl;
    // 0.166666

    vector<vector<int>> edges2 = {
            {2,1},{3,2},{4,1},{5,1},{6,4},{7,1},{8,7}
    };
    cout << Solution().frogPosition(8, edges2, 7, 7) << endl;
    // 0.0

    vector<vector<int>> edges3 = {
            {1,2},{1,3},{1,7},{2,4},{2,6},{3,5}
    };
    cout << Solution().frogPosition(7, edges3, 20, 6) << endl;
    // 0.16666

    vector<vector<int>> edges4 = {
            {2,1},{3,2},{4,3},{5,3},{6,5},{7,3}, {8, 4}, {9, 5}
    };
    cout << Solution().frogPosition(9, edges4, 9, 1) << endl;
    // 0

    vector<vector<int>> edges5 = {
            {2,1},{3,2}
    };
    cout << Solution().frogPosition(3, edges5, 1, 2) << endl;
    // 1.0

    return 0;
}
