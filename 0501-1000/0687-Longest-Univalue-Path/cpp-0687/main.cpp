/// Source : https://leetcode.com/problems/longest-univalue-path/
/// Author : liuyubobobo
/// Time   : 2021-05-21

#include <iostream>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(1)

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
    int res = 0;

public:
    int longestUnivaluePath(TreeNode* root) {

        res = 1;
        dfs(root);
        return res - 1;
    }

private:
    int dfs(TreeNode* node){

        if(!node) return 0;

        int l = dfs(node->left);
        int r = dfs(node->right);

        int tres = 1, ret = 1;
        if(node->left && node->left->val == node->val)
            tres += l, ret = max(ret, 1 + l);
        if(node->right && node->right->val == node->val)
            tres += r, ret = max(ret, 1 + r);
        res = max(res, tres);

        return ret;
    }
};


int main() {

    return 0;
}
