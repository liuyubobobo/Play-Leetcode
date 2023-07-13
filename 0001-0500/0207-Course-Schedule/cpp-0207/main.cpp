/// Source : https://leetcode.com/problems/course-schedule-ii/
/// Author : liuyubobobo
/// Time   : 2018-12-16
/// Updated: 2023-07-13

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// T
/// Time Complexity: O(m + n)
/// Space Complexity: O(m + n)
class Solution {

public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> g(n);
        for(const vector<int>& p: prerequisites){
            int from = p[1];
            int to = p[0];
            g[from].push_back(to);
        }

        vector<int> indegrees(n, 0);
        for(int u = 0; u < n; u ++)
            for(int v: g[u]) indegrees[v] ++;

        queue<int> q;
        int left = n;
        for(int u = 0; u < n; u ++)
            if(indegrees[u] == 0) q.push(u), left --;

        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v: g[u]){
                indegrees[v] --;
                if(indegrees[v] == 0) q.push(v), left --;
            }
        }
        return left == 0;
    }
};


int main() {

    return 0;
}