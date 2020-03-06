/// Source : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
/// Author : liuyubobobo
/// Time   : 2020-03-06

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;


/// Floyed
/// Time Complexity: O(V^3)
/// Space Complexity: O(V^2)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        for(const vector<int>& e: edges)
            dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];

        for(int i = 0; i < n; i ++) dis[i][i] = 0;
        for(int t = 0; t < n; t ++)
            for(int v = 0; v < n; v ++)
                for(int w = 0; w < n; w ++)
                    if(dis[v][t] != INT_MAX && dis[t][w] != INT_MAX)
                        dis[v][w] = min(dis[v][w], dis[v][t] + dis[t][w]);

        int minNum = INT_MAX, res = -1;
        for(int i = 0; i < n; i ++){
            int num = 0;
            for(int v = 0; v < n; v ++)
                if(v != i) num += (dis[i][v] <= distanceThreshold);
            if(num <= minNum) minNum = num, res = i;
        }
        return res;
    }
};


int main() {

    vector<vector<int>> edges = {
            {0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}
    };
    cout << Solution().findTheCity(5, edges, 2) << endl;
    // 0

    return 0;
}
