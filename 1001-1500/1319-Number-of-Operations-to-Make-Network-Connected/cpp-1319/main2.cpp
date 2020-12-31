/// Source : https://leetcode.com/problems/number-of-operations-to-make-network-connected/
/// Author : liuyubobobo
/// Time   : 2020-01-11

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Just count CC number would be enough!
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {

public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(n - 1 > connections.size()) return -1;

        vector<set<int>> g(n);
        for(const vector<int>& e: connections)
            g[e[0]].insert(e[1]), g[e[1]].insert(e[0]);

        vector<bool> visited(n, false);
        int cc = 0;
        for(int i = 0; i < n; i ++)
            if(!visited[i])
                dfs(g, i, visited), cc ++;

        return cc - 1;
    }

private:
    void dfs(const vector<set<int>>& g, int v, vector<bool>& visited){

        visited[v] = true;
        for(int next: g[v])
            if(!visited[next])
                dfs(g, next, visited);
    }
};


int main() {

    vector<vector<int>> c1 = {{0, 1}, {0, 2}, {1, 2}};
    cout << Solution().makeConnected(4, c1) << endl;
    // 1

    vector<vector<int>> c2 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    cout << Solution().makeConnected(6, c2) << endl;
    // 2

    vector<vector<int>> c3 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
    cout << Solution().makeConnected(6, c3) << endl;
    // -1

    vector<vector<int>> c4 = {{0, 1}, {0, 2}, {3, 4}, {2, 3}};
    cout << Solution().makeConnected(5, c4) << endl;
    // 0

    return 0;
}
