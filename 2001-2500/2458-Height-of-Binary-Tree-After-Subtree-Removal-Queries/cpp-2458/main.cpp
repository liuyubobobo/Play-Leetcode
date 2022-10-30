/// Source : https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/
/// Author : liuyubobobo
/// Time   : 2022-10-29

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// DFS
/// Time Complexity: O(n + q)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        int n = dfs_sz(root);

        vector<int> depth(n + 1, -1), subtree_depth(n + 1, -1);
        dfs_depth(root, 0, depth, subtree_depth);

        vector<int> res_table(n + 1, 0);
        dfs_res_table(root, depth, subtree_depth, 0, res_table);

        vector<int> res(queries.size());
        for(int i = 0; i < queries.size(); i ++){
            int q = queries[i];
            res[i] = res_table[q];
        }
        return res;
    }

private:
    void dfs_res_table(TreeNode* node, const vector<int>& depth, const vector<int>& subtree_depth,
                       int pre_max, vector<int>& res_table){

        if(!node) return;
        res_table[node->val] = pre_max;

        int right_max_depth = depth[node->val] + (node->right ? subtree_depth[node->right->val] : 0);
        dfs_res_table(node->left, depth, subtree_depth, max(pre_max, right_max_depth), res_table);

        int left_max_depth = depth[node->val] + (node->left ? subtree_depth[node->left->val] : 0);
        dfs_res_table(node->right, depth, subtree_depth, max(pre_max, left_max_depth), res_table);
    }

    void dfs_depth(TreeNode* node, int d, vector<int>& depth, vector<int>& subtree_depth){

        if(!node) return;

        depth[node->val] = d;

        dfs_depth(node->left, d + 1, depth, subtree_depth);
        dfs_depth(node->right, d + 1, depth, subtree_depth);

        int t = 0;
        if(node->left) t = max(t, subtree_depth[node->left->val]);
        if(node->right) t = max(t, subtree_depth[node->right->val]);
        subtree_depth[node->val] = 1 + t;
    }

    int dfs_sz(TreeNode* node){

        if(!node) return 0;
        return 1 + dfs_sz(node->left) + dfs_sz(node->right);
    }
};


int main() {

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3, new TreeNode(2), nullptr);
    root1->right = new TreeNode(4, new TreeNode(6), new TreeNode(5, nullptr, new TreeNode(7)));

    vector<int> queries1 = {4};
    vector<int> res1 = Solution().treeQueries(root1, queries1);
    for(int e: res1) cout << e << ' '; cout << '\n';
    // 2

    return 0;
}
