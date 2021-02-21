/// Source : https://leetcode.com/problems/tree-of-coprimes/
/// Author : liuyubobobo
/// Time   : 2021-02-21

#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int MAX;

public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {

        int n = nums.size();
        vector<set<int>> g(n);
        for(const vector<int>& e: edges)
            g[e[0]].insert(e[1]), g[e[1]].insert(e[0]);

        MAX = *max_element(nums.begin(), nums.end());
        vector<stack<pair<int, int>>> cur(MAX + 1);
        vector<int> res(n, -1);
        dfs(g, 0, -1, 0, nums, cur, res);
        return res;
    }

private:
    void dfs(const vector<set<int>>& g, int u, int parent, int d,
             const vector<int>& nums, vector<stack<pair<int, int>>>& cur, vector<int>& res){

        int num = nums[u], cur_res_d = -1;
        for(int v = 1; v <= MAX; v ++)
            if(!cur[v].empty() && gcd(num, v) == 1){
                if(res[u] == -1 || cur[v].top().second > cur_res_d){
                    res[u] = cur[v].top().first;
                    cur_res_d = cur[v].top().second;
                }
            }

        cur[num].push({u, d});
        for(int v: g[u])
            if(v != parent)
                dfs(g, v, u, d + 1, nums, cur, res);
        cur[num].pop();
    }

    int gcd(int x, int y){

        if(x < y) swap(x, y);

        if(x % y == 0) return y;
        return gcd(y, x % y);
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {2, 3, 3, 2};
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {1, 3}};
    print_vec(Solution().getCoprimes(nums1, edges1));
    // -1 0 0 1

    vector<int> nums2 = {5,6,10,2,3,6,15};
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    print_vec(Solution().getCoprimes(nums2, edges2));
    // -1 0 -1 0 0 0 -1

    return 0;
}
