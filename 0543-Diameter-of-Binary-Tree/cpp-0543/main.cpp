/// Source : https://leetcode.com/problems/diameter-of-binary-tree/solution/
/// Author : liuyubobobo
/// Time   : 2020-10-15

#include <iostream>

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

private:
    int res;

public:
    int diameterOfBinaryTree(TreeNode* root) {

        res = 0;
        dfs(root);
        return res;
    }

private:
    int dfs(TreeNode* node){

        if(!node) return 0;

        int l = node->left ? 1 + dfs(node->left) : 0;
        int r = node->right ? 1 + dfs(node->right) : 0;
        res = max(res, l + r);
        return max(l, r);
    }
};


int main() {

    return 0;
}
