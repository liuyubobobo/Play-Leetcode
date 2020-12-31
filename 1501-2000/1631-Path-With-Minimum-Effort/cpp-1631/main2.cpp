/// Source : https://leetcode.com/problems/path-with-minimum-effort/
/// Author : liuyubobobo
/// Time   : 2020-11-01

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Edge Sorting and UF
/// Time Complexity: O(nlogn)
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
    int minimumEffortPath(vector<vector<int>>& heights) {

        int R = heights.size(), C = heights[0].size();
        vector<vector<int>> edges;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                if(i + 1 < R) edges.push_back({abs(heights[i][j] - heights[i + 1][j]), i * C + j, (i + 1) * C + j});
                if(j + 1 < C) edges.push_back({abs(heights[i][j] - heights[i][j + 1]), i * C + j, i * C + j + 1});
            }

        sort(edges.begin(), edges.end());

        UF uf(R * C);
        for(const vector<int>& e: edges){
            uf.unionElements(e[1], e[2]);
            if(uf.isConnected(0, R * C - 1)) return e[0];
        }
        return 0;
    }
};


int main() {

    vector<vector<int>> heights1 = {{1,2,2},{3,8,2},{5,3,5}};
    cout << Solution().minimumEffortPath(heights1) << endl;
    // 2

    vector<vector<int>> heights2 = {{1,2,3},{3,8,4},{5,3,5}};
    cout << Solution().minimumEffortPath(heights2) << endl;
    // 1

    vector<vector<int>> heights3 = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    cout << Solution().minimumEffortPath(heights3) << endl;
    // 0

    vector<vector<int>> heights4 = {{3}};
    cout << Solution().minimumEffortPath(heights4) << endl;
    // 0

    vector<vector<int>> heights5 = {{1, 10, 6, 7, 9, 10, 4, 9}};
    cout << Solution().minimumEffortPath(heights5) << endl;
    // 9

    return 0;
}
