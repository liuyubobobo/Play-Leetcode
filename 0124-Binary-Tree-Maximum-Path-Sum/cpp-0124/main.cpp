/// Source : https://leetcode.com/problems/binary-tree-maximum-path-sum/
/// Author : liuyubobobo
/// Time   : 2019-08-09

#include <iostream>
#include <unordered_map>

using namespace std;


/// Two Pass DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

private:
    unordered_map<TreeNode*, int> map;
    int res = INT_MIN;

public:
    int maxPathSum(TreeNode* root) {

        dfs1(root);
        dfs2(root);
        return res;
    }

private:
    void dfs2(TreeNode* node){

        if(!node) return;
        res = max(res, node->val + max(0, map[node->left]) + max(0, map[node->right]));
        dfs2(node->left);
        dfs2(node->right);
    }

    int dfs1(TreeNode* node){

        int left = node->left ? dfs1(node->left) : 0;
        int right = node->right ? dfs1(node->right) : 0;
        return map[node] = node->val + max(0, max(left, right));
    }
};


int main() {

    return 0;
}