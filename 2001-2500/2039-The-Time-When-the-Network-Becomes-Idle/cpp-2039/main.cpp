/// Source : https://leetcode.com/problems/the-time-when-the-network-becomes-idle/
/// Author : liuyubobobo
/// Time   : 2021-10-18

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(n + m)
/// Space Complexity: O(n + m)
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {

        int n = patience.size();

        vector<vector<int>> g(n);
        for(const vector<int>& e: edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        vector<int> dis(n, -1);
        queue<int> q;
        q.push(0);
        dis[0] = 0;
        while(!q.empty()){
            int u = q.front();q.pop();

            for(int v: g[u])
                if(dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
        }

        int res = 0;
        for(int i = 1; i < n; i ++){
            int d = 2 * dis[i];
            int num = (d - 1) / patience[i];
            res = max(res, patience[i] * num + d);
        }
        return res;
    }
};


int main() {

    return 0;
}
