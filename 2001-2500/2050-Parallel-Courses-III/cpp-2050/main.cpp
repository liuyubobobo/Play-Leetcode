/// Source : https://leetcode.com/problems/parallel-courses-iii/
/// Author : liuyubobobo
/// Time   : 2021-10-23

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O((n + m) * logn)
/// Space Complexity: O(n + m)
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        vector<vector<int>> g(n);
        vector<int> in_degrees(n, 0);
        for(const vector<int>& e: relations){
            int u = e[0] - 1, v = e[1] - 1;
            g[u].push_back(v);
            in_degrees[v] ++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // complete time, index
        for(int u = 0; u < n; u ++)
            if(in_degrees[u] == 0) pq.push({time[u], u});

        int res = 0;
        while(!pq.empty()){
            int complete_time = pq.top().first, u = pq.top().second;
            pq.pop();

            res = max(res, complete_time);

            for(int v: g[u]){
                in_degrees[v] --;
                if(in_degrees[v] == 0)
                    pq.push({complete_time + time[v], v});
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
