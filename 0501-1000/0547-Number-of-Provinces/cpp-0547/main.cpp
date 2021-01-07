/// Source : https://leetcode.com/problems/number-of-provinces/
/// Author : liuyubobobo
/// Time   : 2021-01-06

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

private:
    int n;

public:
    int findCircleNum(vector<vector<int>>& M) {

        n = M.size();
        if(!n) return 0;

        int res = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i ++)
            if(!visited[i]){
                dfs(M, i, visited);
                res ++;
            }
        return res;
    }

private:
    void dfs(const vector<vector<int>>& M, int u, vector<bool>& visited){

        visited[u] = true;
        for(int i = 0; i < n; i ++)
            if(M[u][i] && !visited[i])
                dfs(M, i, visited);
    }
};


int main() {

    return 0;
}
