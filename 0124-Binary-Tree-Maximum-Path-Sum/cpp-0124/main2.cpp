/// Source : https://leetcode.com/problems/binary-tree-maximum-path-sum/
/// Author : liuyubobobo
/// Time   : 2019-08-09

#include <iostream>
#include <unordered_map>

using namespace std;


/// One Pass DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

private:
    int res = INT_MIN;

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

private:
    int dfs(TreeNode* node){

        int left = node->left ? dfs(node->left) : 0;
        int right = node->right ? dfs(node->right) : 0;

        res = max(res, node->val + max(0, left) + max(0, right));

        return node->val + max(0, max(left, right));
    }
};


int main() {

    return 0;
}