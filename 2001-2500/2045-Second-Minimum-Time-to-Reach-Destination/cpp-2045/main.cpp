#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        vector<set<int>> g(n);
        for(const vector<int>& e: edges){
            int u = e[0] - 1, v = e[1] - 1;
            g[u].insert(v), g[v].insert(u);
        }

        int min_t = dij(n, g, change, time);
//        cout << "min_t = " << min_t << endl;

        int res = min_t + (min_t % (2 * change) < change ? 0 : (2 * change - min_t % (2 * change))) + time;
        res += (res % (2 * change) < change ? 0 : (2 * change - res % (2 * change))) + time;
//        cout << "init res = " << res << endl;

        for(const vector<int>& e: edges){
            int u = e[0] - 1, v = e[1] - 1;
            g[u].erase(v), g[v].erase(u);
            int tres = dij(n, g, change, time);
            if(tres != min_t){
//                cout << tres << endl;
                assert(tres > min_t);
                res = min(res, tres);
            }
            g[u].insert(v), g[v].insert(u);
        }
        return res;
    }

private:
    int dij(int n, const vector<set<int>>& g, int change, int time){

        vector<int> dis(n, INT_MAX);
        vector<bool> visited(n, false);
        // t, u
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dis[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            int d = pq.top().first, u = pq.top().second;
            pq.pop();

            if(visited[u]) continue;
            visited[u] = true;

            for(int v: g[u])
                if(!visited[v]){
                    int nextd = d + (d % (2 * change) < change ? 0 : (2 * change - d % (2 * change))) + time;
                    if(nextd < dis[v]){
                        dis[v] = nextd;
                        pq.push({nextd, v});
                    }
                }
        }
        return dis.back();
    }
};

int main() {

    vector<vector<int>> edges1 = {
            {1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}
    };
    cout << Solution().secondMinimum(5, edges1, 3, 5) << endl;
    // min_t : 6
    // 13

    vector<vector<int>> edges2 = {
            {1, 2}
    };
    cout << Solution().secondMinimum(2, edges2, 3, 2) << endl;
    // min_t : 3
    // 11

    return 0;
}
