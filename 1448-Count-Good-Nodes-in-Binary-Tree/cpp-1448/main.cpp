/// Source : https://leetcode.com/problems/count-good-nodes-in-binary-tree/
/// Author : liuyubobobo
/// Time   : 2020-05-16

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

public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

private:
    int dfs(TreeNode* node, int cur_max){

        if(!node) return 0;

        int res = node->val >= cur_max;
        res += dfs(node->left, max(node->val, cur_max));
        res += dfs(node->right, max(node->val, cur_max));
        return res;
    }
};


int main() {

    return 0;
}
