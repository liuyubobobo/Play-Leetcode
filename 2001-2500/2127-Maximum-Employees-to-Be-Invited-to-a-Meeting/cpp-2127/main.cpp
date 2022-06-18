/// Source : https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/
/// Author : liuyubobobo
/// Time   : 2022-01-01

#include <iostream>
#include <vector>

using namespace std;


/// Successor Graph
/// This problem is not a very standard Successor Graph Problem, a little bit harder and Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {

        int n = favorite.size();

        vector<int> in_degrees(n, 0);
        for(int u = 0; u < n; u ++)
            in_degrees[favorite[u]] ++;

        vector<bool> in_tree(n, false);
        for(int u = 0; u < n; u ++)
            if(!in_tree[u] && in_degrees[u] == 0){
                int cur = u;
                while(in_degrees[cur] == 0){
                    in_tree[cur] = true;
                    cur = favorite[cur];
                    in_degrees[cur] --;
                }
            }

        vector<vector<int>> g(n);
        for(int u = 0; u < n; u ++)
            g[favorite[u]].push_back(u);

        vector<int> max_d(n, 0);
        vector<bool> visited(n, false);
        int res = 0, max2 = 0;
        for(int u = 0; u < n; u ++){
            if(in_tree[u]) continue;

            int s = u;
            vector<int> cycle_points;
            while(!visited[s]){
                cycle_points.push_back(s);
                visited[s] = true;
                s = favorite[s];
            }

            int first = 0, second = 0;
            for(int v: cycle_points){
                dfs(g, v, in_tree, visited, max_d);
                if(max_d[v] - 1 > first) second = first, first = max_d[v] - 1;
                else if(max_d[v] - 1 > second) second = max_d[v] - 1;
            }

            if(cycle_points.size() == 2) max2 += 2 + first + second;
            else res = max(res, (int)cycle_points.size());
        }
        return max(res, max2);
    }

private:
    void dfs(const vector<vector<int>>& g, int u, const vector<bool>& in_tree,
             vector<bool>& visited, vector<int>& max_d){

        visited[u] = true;
        int res = 1;
        for(int v: g[u])
            if(!visited[v] && in_tree[v]){
                dfs(g, v, in_tree, visited, max_d);
                res = max(res, 1 + max_d[v]);
            }
        max_d[u] = res;
    }
};


int main() {

    vector<int> fav1 = {2, 2, 1, 2};
    cout << Solution().maximumInvitations(fav1) << endl;
    // 3

    vector<int> fav2 = {1, 2, 0};
    cout << Solution().maximumInvitations(fav2) << endl;
    // 3

    vector<int> fav3 = {3, 0, 1, 4, 1};
    cout << Solution().maximumInvitations(fav3) << endl;
    // 4

    vector<int> fav4 = {1,2,3,4,5,6,3,8,9,10,11,8};
    cout << Solution().maximumInvitations(fav4) << endl;
    // 4

    vector<int> fav5 = {1,0,0,2,1,4,7,8,9,6,7,10,8};
    cout << Solution().maximumInvitations(fav5) << endl;
    // 6

    vector<int> fav6 = {1,0,3,2,5,6,7,4,9,8,11,10,11,12,10};
    cout << Solution().maximumInvitations(fav6) << endl;
    // 11

    vector<int> fav7 = {6,10,10,0,6,0,4,4,1,3,3};
    cout << Solution().maximumInvitations(fav7) << endl;
    // 8

    return 0;
}
