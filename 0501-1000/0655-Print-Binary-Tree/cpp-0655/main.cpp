/// Source : https://leetcode.com/problems/print-binary-tree/
/// Author : liuyubobobo
/// Time   : 2022-08-21

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)

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
    vector<vector<string>> printTree(TreeNode* root) {

        int d = dfs_depth(root);

        vector<vector<string>> res(d, vector<string>((1 << d) - 1, ""));
        dfs(root, 0, 0, (1 << d) - 1, res);
        return res;
    }

private:
    void dfs(TreeNode* node, int d, int l, int r, vector<vector<string>>& res){

        if(!node) return;

        int mid = l + (r - l) / 2;
        res[d][mid] = to_string(node->val);

        dfs(node->left, d + 1, l, mid - 1, res);
        dfs(node->right, d + 1, mid + 1, r, res);
    }

    int dfs_depth(TreeNode* node){

        if(!node) return 0;

        int res = 0;
        res = max(res, dfs_depth(node->left));
        res = max(res, dfs_depth(node->right));
        return res + 1;
    }
};


int main() {

    return 0;
}
