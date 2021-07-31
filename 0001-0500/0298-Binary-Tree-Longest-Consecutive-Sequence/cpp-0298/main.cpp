/// Source : https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
/// Author : liuyubobobo
/// Time   : 2021-07-31

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
    int res = 0;

public:
    int longestConsecutive(TreeNode* root) {

        res = 0;
        dfs(root, 1);
        return res;
    }

private:
    void dfs(TreeNode* node, int k){

        res = max(res, k);

        if(node->left){
            if(node->left->val == node->val + 1) dfs(node->left, k + 1);
            else dfs(node->left, 1);
        }

        if(node->right){
            if(node->right->val == node->val + 1) dfs(node->right, k + 1);
            else dfs(node->right, 1);
        }
    }
};


int main() {

    return 0;
}
