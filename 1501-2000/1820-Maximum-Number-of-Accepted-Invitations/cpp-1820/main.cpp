/// Source : https://leetcode.com/problems/maximum-number-of-accepted-invitations/
/// Author : liuyubobobo
/// Time   : 2021-06-11

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Hungarian Algorithm
/// Time Complexity: O(m^2 * n)
/// Space Complexity: O(m * n)
class MaxMatching{

private:
    int m, n; // m - row size, n = column size
    vector<unordered_set<int>> g;
    vector<int> matching;

public:
    MaxMatching(int m, int n) : m(m), n(n), g(m), matching(n, -1){}

    void add_edge(int u, int v){
        assert(u >= 0 && u < m && v >= 0 && v < n);
        g[u].insert(v);
    }

    int solve(){

        int res = 0;
        for(int i = 0; i < m; i ++){
            vector<bool> visited(n, false);
            if(dfs(i, visited)) res ++;
        }
        return res;
    }

private:
    bool dfs(int u, vector<bool>& visited){

        for(int v: g[u])
            if(!visited[v]){
                visited[v] = true;
                if(matching[v] == -1 || dfs(matching[v], visited)){
                    matching[v] = u;
                    return true;
                }
            }
        return false;
    }
};

class Solution {
public:
    int maximumInvitations(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        MaxMatching maxMatching(m, n);

        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(grid[i][j]) maxMatching.add_edge(i, j);

        return maxMatching.solve();
    }
};


int main() {

    vector<vector<int>> grid1 = {
            {1, 1, 1},
            {1, 0, 1},
            {0, 0, 1}
    };
    cout << Solution().maximumInvitations(grid1) << endl;
    // 3

    return 0;
}
