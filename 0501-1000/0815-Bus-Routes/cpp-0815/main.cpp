/// Source : https://leetcode.com/problems/bus-routes/
/// Author : liuyubobobo
/// Time   : 2021-06-27

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if(source == target) return 0;

        int n = routes.size();

        unordered_map<int, set<int>> stop2route;
        for(int route = 0; route < n; route ++)
            for(int stop : routes[route])
                stop2route[stop].insert(route);

        vector<set<int>> g(n);
        for(int r1 = 0; r1 < n; r1 ++)
            for(int stop: routes[r1])
                for(int r2: stop2route[stop])
                    if(r1 != r2)
                        g[r1].insert(r2), g[r2].insert(r1);

        queue<int> q;
        vector<int> visited(n, -1);
        for(int route: stop2route[source]){
            q.push(route);
            visited[route] = 1;
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            if(stop2route[target].count(cur)) return visited[cur];

            for(int next: g[cur])
                if(visited[next] == -1){
                    q.push(next);
                    visited[next] = visited[cur] + 1;
                }
        }
        return -1;
    }
};


int main() {

    vector<vector<int>> route1 = {{1, 2, 7}, {3, 6, 7}};
    cout << Solution().numBusesToDestination(route1, 1, 6) << endl;
    // 2

    vector<vector<int>> route2 = {{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}};
    cout << Solution().numBusesToDestination(route2, 15, 12) << endl;
    // -1

    vector<vector<int>> route3 = {{1, 7}, {3, 5}};
    cout << Solution().numBusesToDestination(route3, 5, 5) << endl;
    // 0

    return 0;
}
