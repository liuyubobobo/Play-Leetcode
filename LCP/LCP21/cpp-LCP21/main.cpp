/// Source : https://leetcode-cn.com/problems/Za25hA/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;


/// Loop finding and BFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int chaseGame(vector<vector<int>>& edges, int startA, int startB) {

        int n = edges.size();
        vector<unordered_set<int>> g(n);
        for(vector<int>& e: edges){
            e[0] --, e[1] --;
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        startA --, startB --;

        for(int next: g[startA])
            if(next == startB) return 1;

        int circle_len = 0;
        vector<bool> in_circle = get_circle(g, circle_len);
//        for(int e: in_circle) cout << e << " "; cout << endl;
        assert(circle_len >= 3);
        if(circle_len >= 4 & in_circle[startB]) return -1;

        int bestInCircleB = -1, bestInCircleBDis = -1;
        bfs(g, in_circle, startB, bestInCircleB, bestInCircleBDis);
        assert(bestInCircleB != -1 && bestInCircleBDis != -1);

        vector<int> disA = bfs(g, startA);
        if(circle_len >= 4 && disA[bestInCircleB] > bestInCircleBDis + 1) return -1;

        vector<int> disB = bfs(g, startB);
        int res = INT_MIN;
        for(int end = 0; end < g.size(); end ++)
            if(g[end].size() == 1 && disA[end] > disB[end] + 1)
                res = max(res, disA[end]);
        return res;
    }

private:
    vector<int> bfs(const vector<unordered_set<int>>& g, int s){

        vector<int> dis(g.size(), -1);
        dis[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v: g.at(u))
                if(dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
        }
        return dis;
    }

    void bfs(const vector<unordered_set<int>>& g, const vector<bool>& in_circle, int s,
             int& t, int& d){

        vector<int> dis(g.size(), -1);
        dis[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(in_circle[u]){
                t = u, d = dis[u];
                return;
            }

            for(int v: g.at(u))
                if(dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
        }
        assert(false);
        return;
    }

    vector<bool> get_circle(const vector<unordered_set<int>>& g, int& circle_len){

        vector<int> pre(g.size(), -1);
        int start = -1;
        assert(dfs(g, 0, 0, pre, start));

        vector<bool> in_circle(g.size(), false);
        in_circle[start] = true;
        int cur = pre[start];
        circle_len ++;
        while(cur != start){
            in_circle[cur] = true;
            cur = pre[cur];
            circle_len ++;
        }
        return in_circle;
    }

    bool dfs(const vector<unordered_set<int>>& g, int u, int p, vector<int>& pre, int& start){

        pre[u] = p;
        for(int v: g.at(u))
            if(v != p){
                if(pre[v] == -1){
                    if(dfs(g, v, u, pre, start)) return true;
                }
                else{
                    pre[v] = u;
                    start = v;
                    return true;
                }
            }
        return false;
    }
};


int main() {

    vector<vector<int>> edges1 = {{1,2},{2,3},{3,4},{4,1},{2,5},{5,6}};
    cout << Solution().chaseGame(edges1, 3, 5) << endl;
    // 3

    vector<vector<int>> edges2 = {{1,2},{2,3},{3,4},{4,1}};
    cout << Solution().chaseGame(edges2, 1, 3) << endl;
    // -1

    vector<vector<int>> edges3 = {{1,2},{2,3},{3,1},{3,6},{2,4},{4,5},{5,8},{4,7}};
    cout << Solution().chaseGame(edges3, 8, 7) << endl;
    // 3

    vector<vector<int>> edges4 = {{1,2},{2,3},{3,1},{3,6},{2,4},{4,5},{5,8},{4,7},{8,9}};
    cout << Solution().chaseGame(edges4, 9, 7) << endl;
    // 6

    return 0;
}
