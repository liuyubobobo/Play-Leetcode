/// Source : https://leetcode.com/problems/correct-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2020-11-21

#include <iostream>
#include <unordered_set>

using namespace std;


/// Using HashSet and DFS
/// Time Complexity: O(n)
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

private:
    unordered_set<TreeNode*> set;

public:
    TreeNode* correctBinaryTree(TreeNode* root) {

        set.clear();
        return dfs(root);
    }

private:
    TreeNode* dfs(TreeNode* node){

        set.insert(node);
        if(node->right && set.count(node->right)) return nullptr;

        if(node->right) node->right = dfs(node->right);
        if(node->left) node->left = dfs(node->left);
        return node;
    }
};


int main() {

    return 0;
}
