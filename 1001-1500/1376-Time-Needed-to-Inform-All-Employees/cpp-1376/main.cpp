/// Source : https://leetcode.com/problems/time-needed-to-inform-all-employees/
/// Author : liuyubobobo
/// Time   : 2020-03-07

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// DFS
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

        vector<set<int>> g(n, set<int>());
        for(int i = 0; i < n; i ++)
            if(i != headID) g[i].insert(manager[i]), g[manager[i]].insert(i);

        vector<bool> visited(n, false);
        return dfs(g, n, headID, visited, informTime);
    }

private:
    int dfs(const vector<set<int>>& g, int n, int node,
            vector<bool>& visited, const vector<int>& informTime){

        visited[node] = true;
        int res = 0;
        for(int next: g[node])
            if(!visited[next])
                res = max(res, dfs(g, n, next, visited, informTime));
        return res + informTime[node];
    }
};


int main() {

    vector<int> manager1 = {-1};
    vector<int> informTime1 = {0};
    cout << Solution().numOfMinutes(1, 0, manager1, informTime1) << endl;
    // 0

    vector<int> manager2 = {2,2,-1,2,2,2};
    vector<int> informTime2 = {0,0,1,0,0,0};
    cout << Solution().numOfMinutes(6, 2, manager2, informTime2) << endl;
    // 1

    vector<int> manager3 = {1,2,3,4,5,6,-1};
    vector<int> informTime3 = {0,6,5,4,3,2,1};
    cout << Solution().numOfMinutes(7, 6, manager3, informTime3) << endl;
    // 21

    return 0;
}
