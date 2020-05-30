/// Source : https://leetcode.com/problems/course-schedule-iv/
/// Author : liuyubobobo
/// Time   : 2020-05-30

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Check every query using DFS, cache to void repeat calculations
/// Time Complexity: O(n^3 + q)
/// Space Complexity: O(n^2)
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<unordered_set<int>> g(n);
        for(const vector<int>& e: prerequisites) g[e[0]].insert(e[1]);

        vector<vector<int>> reach(n, vector<int>(n, -1));
        vector<bool> res;
        for(const vector<int>& q: queries)
            res.push_back(dfs(n, g, q[0], q[1], reach));
        return res;
    }

private:
    bool dfs(int n, const vector<unordered_set<int>>& g,
             int a, int b, vector<vector<int>>& reach){

        if(reach[a][b] != -1) return reach[a][b];
        if(a == b) return true;

        for(int next: g[a]){
            reach[a][next] = true;
            reach[next][b] = dfs(n, g, next, b, reach);
            if(reach[next][b]) return reach[a][b] = true;
        }
        return false;
    }
};


void print_vec(const vector<bool>& res){
    for(int e: res) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> p1 = {{1, 0}}, q1 = {{0, 1}, {1, 0}};
    print_vec(Solution().checkIfPrerequisite(2, p1, q1));
    // 0 1

    vector<vector<int>> p2 = {}, q2 = {{1, 0}, {0, 1}};
    print_vec(Solution().checkIfPrerequisite(2, p2, q2));
    // 0 0

    vector<vector<int>> p3 = {{1, 2}, {1, 0}, {2, 0}}, q3 = {{1, 0}, {1, 2}};
    print_vec(Solution().checkIfPrerequisite(3, p3, q3));
    // 1 1

    vector<vector<int>> p4 = {{1, 0}, {2, 0}}, q4 = {{0, 1}, {2, 0}};
    print_vec(Solution().checkIfPrerequisite(3, p4, q4));
    // 0 1

    vector<vector<int>> p5 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}}, q5 = {{0, 4}, {4, 0}, {1, 3}, {3, 0}};
    print_vec(Solution().checkIfPrerequisite(5, p5, q5));
    // 1 0 1 0

    return 0;
}
