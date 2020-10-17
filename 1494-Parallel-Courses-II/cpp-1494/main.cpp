/// Source : https://leetcode.com/problems/parallel-courses-ii/
/// Author : liuyubobobo
/// Time   : 2020-10-17

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {

        vector<vector<int>> g(n);
        vector<int> indegrees(n, 0);
        for(const vector<int>& e: dependencies){
            g[e[0] - 1].push_back(e[1] - 1);
            indegrees[e[1] - 1] ++;
        }

        queue<int> q;
        for(int i = 0; i < n; i ++)
            if(!indegrees[i]) q.push(i);

        int res = 0;
        while(!q.empty()){

            int sz = min((int)q.size(), k);
            res ++;

            while(sz --){
                int cur = q.front();
                q.pop();
                for(int next: g[cur]){
                    indegrees[next] --;
                    if(!indegrees[next]) q.push(next);
                }
            }
        }
        return res;
    }
};


int main() {

    vector<vector<int>> dep1 = {{2, 1}, {3, 1}, {1, 4}};
    cout << Solution().minNumberOfSemesters(4, dep1, 2) << endl;
    // 3

    vector<vector<int>> dep2 = {{2, 1}, {3, 1}, {4, 1}, {1, 5}};
    cout << Solution().minNumberOfSemesters(5, dep2, 2) << endl;
    // 4

    vector<vector<int>> dep3 = {};
    cout << Solution().minNumberOfSemesters(11, dep3, 2) << endl;
    // 6

    vector<vector<int>> dep4 = {{1,2},{1,3},{7,5},{7,6},{4,8},{8,9},{9,10},{10,11},{11,12}};
    cout << Solution().minNumberOfSemesters(12, dep4, 2) << endl;
    // 6

    return 0;
}
