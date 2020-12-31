/// Source : https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
/// Author : liuyubobobo
/// Time   : 2020-02-01

#include <iostream>

using namespace std;


/// Two DFS
/// Time Complexity: O(n)
/// Space Complexity: O(logn)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int maxProduct(TreeNode* root) {

        dfs1(root);

        long long res = 0ll;
        dfs2(root, root, res);
        return res % MOD;
    }

private:
    int dfs1(TreeNode* node){

        if(!node) return 0;

        int x = dfs1(node->left);
        int y = dfs1(node->right);
        node->val += (x + y);
        return node->val;
    }

    void dfs2(TreeNode* root, TreeNode* node, long long& res){

        if(node->left){
            res = max(res, (long long)(root->val - node->left->val) * (long long)node->left->val);
            dfs2(root, node->left, res);
        }

        if(node->right){
            res = max(res, (long long)(root->val - node->right->val) * (long long)node->right->val);
            dfs2(root, node->right, res);
        }
    }
};


int main() {

    return 0;
}
