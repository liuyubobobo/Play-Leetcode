/// Source : https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
/// Author : liuyubobobo
/// Time   : 2018-03-09

#include <iostream>
#include <vector>

using namespace std;


/// Based on Dijkstra
/// Time Complexity: O(K*N)
/// Space Complexity: O(N^2)
class Solution {

private:
    int max_price = 1000000;

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

        vector<vector<int>> g(n, vector<int>(n, max_price));
        for(const vector<int>& flight: flights)
            g[flight[0]][flight[1]] = flight[2];

        vector<int> dis(n, max_price);
        for(int i = 0 ; i < n ; i ++)
            dis[i] = g[src][i];
        dis[src] = 0;

        for(int i = 0 ; i < K ; i ++) {

            vector<int> new_dis = dis;
            for(const vector<int>& flight: flights)
                if(dis[flight[0]] + flight[2] < new_dis[flight[1]])
                    new_dis[flight[1]] = dis[flight[0]] + flight[2];
            dis = new_dis;
        }

        return dis[dst] == max_price ? -1 : dis[dst];
    }
};


int main() {

    vector<vector<int>> edges1 = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << Solution().findCheapestPrice(3, edges1, 0, 2, 1) << endl;
    // 200

    // ---

    vector<vector<int>> edges2 = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << Solution().findCheapestPrice(3, edges2, 0, 2, 0) << endl;
    // 500

    // ---

    vector<vector<int>> edges3 = {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}};
    cout << Solution().findCheapestPrice(4, edges3, 0, 3, 1) << endl;
    // 6

    vector<vector<int>> edges4 = {{0,3,7},{4,5,3},{6,4,8},{2,0,10},{6,5,6},{1,2,2},{2,5,9},{2,6,8},{3,6,3},{4,0,10},{4,6,8},{5,2,6},{1,4,3},{4,1,6},{0,5,10},{3,1,5},{4,3,1},{5,4,10},{0,1,6}};
    cout << Solution().findCheapestPrice(7, edges4, 2, 4, 1) << endl;
    // 16

    return 0;
}