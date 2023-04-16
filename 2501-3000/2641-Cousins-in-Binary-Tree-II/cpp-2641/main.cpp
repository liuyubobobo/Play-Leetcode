/// Source : https://leetcode.com/problems/cousins-in-binary-tree-ii/description/
/// Author : liuyubobobo
/// Time   : 2023-04-15

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// DFS
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
public:
    TreeNode* replaceValueInTree(TreeNode* root) {

        vector<int> depth_sum;
        dfs(root, nullptr, 0, depth_sum);

        return dfs_replace(root, nullptr, 0, depth_sum);
    }

private:
    TreeNode* dfs_replace(TreeNode* node, TreeNode* parent, int depth, const vector<int>& depth_sum){

        if(node == nullptr) return nullptr;

        TreeNode* left = dfs_replace(node->left, node, depth + 1, depth_sum);
        TreeNode* right = dfs_replace(node->right, node, depth + 1, depth_sum);
        TreeNode* ret = new TreeNode(0, left, right);
        if(parent != nullptr)
            ret->val = depth_sum[depth] - (parent->left ? parent->left->val : 0) - (parent->right ? parent->right->val : 0);
        return ret;
    }

    void dfs(TreeNode* node, TreeNode* parent, int depth, vector<int>& depth_sum){

        if (node == nullptr) return;

        while(depth >= depth_sum.size()) depth_sum.push_back(0);
        depth_sum[depth] += node->val;

        dfs(node->left, node, depth + 1, depth_sum);
        dfs(node->right, node, depth + 1, depth_sum);
    }
};


int main() {

    return 0;
}
