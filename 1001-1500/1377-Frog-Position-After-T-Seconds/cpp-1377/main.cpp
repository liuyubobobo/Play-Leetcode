/// Source : https://leetcode.com/problems/frog-position-after-t-seconds/
/// Author : liuyubobobo
/// Time   : 2020-03-07

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// DFS to get the path
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {

        vector<set<int>> g(n, set<int>());
        for(const vector<int>& e: edges)
            g[e[0] - 1].insert(e[1] - 1), g[e[1] - 1].insert(e[0] - 1);

        vector<int> path;
        target --;
        dfs(g, 0, -1, target, path);
//        for(int e: path) cout << e << " "; cout << endl;
        if(t + 1 < path.size()) return 0.0;
        if(t + 1 > path.size() && (target == 0 && g[target].size() || g[target].size() > 1)) return 0.0;

        double res = 1.0;
        for(int i = 0; i + 1 < path.size(); i ++){
//            cout << g[path[i]].size() << endl;
            res /= (double)(g[path[i]].size() - !!i);
        }
        return res;
    }

private:
    bool dfs(const vector<set<int>>& g, int cur, int parent, int target,
             vector<int>& path){

        path.push_back(cur);
        if(cur == target) return true;
        for(int next: g[cur])
            if(next != parent){
                if(dfs(g, next, cur, target, path)) return true;
            }
        path.pop_back();
        return false;
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

    return 0;
}
