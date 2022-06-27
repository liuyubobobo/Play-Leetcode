/// Source : https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/
/// Author : liuyubobobo
/// Time   : 2022-06-25

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// DFS
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {

        int n = nums.size();
        vector<vector<int>> tree(n);
        for(const vector<int>& e: edges){
            int u = e[0], v = e[1];
            tree[u].push_back(v), tree[v].push_back(u);
        }

        vector<vector<bool>> is_ancestor(n, vector<bool>(n, false));
        vector<int> path;
        dfs_ancestor(tree, 0, -1, path, is_ancestor);

        vector<int> xor_subtree(n, 0);
        dfs_xor_subtree(tree, 0, -1, nums, xor_subtree);

        int res = INT_MAX;
        for(int i = 0; i < edges.size(); i ++){
            for(int j = i + 1; j < edges.size(); j ++){

                int u1 = edges[i][0], v1 = edges[i][1];
                int root1 = (is_ancestor[u1][v1] ? v1 : u1);

                int xor1 = (xor_subtree[0] ^ xor_subtree[root1]);
                int xor2 = xor_subtree[root1];
                int xor3 = 0;

                int u2 = edges[j][0], v2 = edges[j][1];
                int root2 = is_ancestor[u2][v2] ? v2 : u2;

                if(is_ancestor[root1][root2]){
                    xor3 = xor_subtree[root2];
                    xor2 ^= xor3;
                }
                else if(is_ancestor[root2][root1]){
                    xor1 = (xor_subtree[0] ^ xor_subtree[root2]);
                    xor3 = xor_subtree[root2] ^ xor2;
                }
                else{
                    assert(is_ancestor[0][root2]);
                    xor3 = xor_subtree[root2];
                    xor1 ^= xor3;
                }

                res = min(res, max3(xor1, xor2, xor3) - min3(xor1, xor2, xor3));
            }
        }
        return res;
    }

private:
    int max3(int a, int b, int c){
        return max(a, max(b, c));
    }

    int min3(int a, int b, int c){
        return min(a, min(b, c));
    }

    void dfs_xor_subtree(const vector<vector<int>>& tree, int u, int p,
                         const vector<int>& nums, vector<int>& xor_subtree){

        xor_subtree[u] ^= nums[u];
        for(int v: tree[u]){
            if(v == p) continue;
            dfs_xor_subtree(tree, v, u, nums, xor_subtree);
            xor_subtree[u] ^= xor_subtree[v];
        }
    }

    void dfs_ancestor(const vector<vector<int>>& tree, int u, int p,
                      vector<int>& path, vector<vector<bool>>& is_ancestor){

        for(int x: path)
            is_ancestor[x][u] = true;

        path.push_back(u);
        for(int v: tree[u]){
            if(v == p) continue;
            dfs_ancestor(tree, v, u, path, is_ancestor);
        }
        path.pop_back();
    }
};


int main() {

    vector<int> nums2 = {5, 5, 2, 4, 4, 2};
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {5, 2}, {4, 3}, {1, 3}};
    cout << Solution().minimumScore(nums2, edges2) << '\n';

    return 0;
}
