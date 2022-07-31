/// Source : https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
/// Author : liuyubobobo
/// Time   : 2022-07-31

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


/// BFS
/// Time Compelxity: O(n)
/// Space Compelxity: O(n)
class Solution {
public:
    int closestMeetingNode(vector<int>& g, int node1, int node2) {

        int n = g.size();
        vector<int> dis1 = bfs(n, g, node1);
        vector<int> dis2 = bfs(n, g, node2);

        int best = INT_MAX, res = -1;
        for(int u = 0; u < n; u ++){
            if(dis1[u] == -1 || dis2[u] == -1) continue;
            int d = max(dis1[u], dis2[u]);
            if(d < best) best = d, res = u;
        }
        return res;
    }

private:
    vector<int> bfs(int n, const vector<int>& g, int s){

        vector<int> dis(n, -1);

        queue<int> q;
        q.push(s);
        dis[s] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            int v = g[u];
            if(v == -1 || dis[v] != -1) continue;

            dis[v] = dis[u] + 1;
            q.push(v);
        }
        return dis;
    }
};


int main() {

    return 0;
}
