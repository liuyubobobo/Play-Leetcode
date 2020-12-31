/// Source : https://leetcode.com/problems/min-cost-to-connect-all-points/
/// Author : liuyubobobo
/// Time   : 2020-09-12

#include <iostream>
#include <vector>

using namespace std;


/// Kruskal MST
/// Time Complexity: O(n^2log(n^2))
/// Space Complexity: O(n)
class UF{

private:
    vector<int> parent;

public:
    UF(int n){
        for(int i = 0 ; i < n ; i ++)
            parent.push_back(i);
    }

    int find(int p){
        if( p != parent[p] )
            parent[p] = find( parent[p] );
        return parent[p];
    }

    bool isConnected(int p , int q){
        return find(p) == find(q);
    }

    void unionElements(int p, int q){

        int pRoot = find(p);
        int qRoot = find(q);

        if( pRoot == qRoot )
            return;

        parent[pRoot] = qRoot;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                edges.push_back({dis(points[i], points[j]), {i, j}});

        sort(edges.begin(), edges.end());

        int res = 0;
        UF uf(n);
        for(const pair<int, pair<int, int>>& e: edges){
            int w = e.first, a = e.second.first, b = e.second.second;
            if(!uf.isConnected(a, b)){
                res += w;
                uf.unionElements(a, b);
            }
        }
        return res;
    }

private:
    int dis(const vector<int>& p1, const vector<int>& p2){
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};


int main() {

    vector<vector<int>> points1 = {
            {0,0},{2,2},{3,10},{5,2},{7,0}
    };
    cout << Solution().minCostConnectPoints(points1) << endl;
    // 20

    vector<vector<int>> points2 = {
            {3,12},{-2,5},{-4,1}
    };
    cout << Solution().minCostConnectPoints(points2) << endl;
    // 18

    vector<vector<int>> points3 = {
            {0,0},{1,1},{1,0},{-1,1}
    };
    cout << Solution().minCostConnectPoints(points3) << endl;
    // 4

    vector<vector<int>> points4 = {
            {-1000000,-1000000},{1000000,1000000}
    };
    cout << Solution().minCostConnectPoints(points4) << endl;
    // 400000

    vector<vector<int>> points5 = {
            {0, 0}
    };
    cout << Solution().minCostConnectPoints(points5) << endl;
    // 0

    return 0;
}