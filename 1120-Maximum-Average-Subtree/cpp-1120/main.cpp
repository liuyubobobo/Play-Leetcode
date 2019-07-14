/// Source : https://leetcode.com/problems/maximum-average-subtree/
/// Author : liuyubobobo
/// Time   : 2019-07-13

#include <iostream>
#include <unordered_map>

using namespace std;


/// DFS
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
    unordered_map<TreeNode*, int> sum;
    unordered_map<TreeNode*, int> sz;

public:
    double maximumAverageSubtree(TreeNode* root) {

        dfsSum(root);
        dfsSz(root);
        return dfsRes(root);
    }

private:
    int dfsSum(TreeNode* node){

        if(!node) return 0;
        int left = dfsSum(node->left);
        int right = dfsSum(node->right);
        sum[node] = left + right + node->val;
        return sum[node];
    }

    int dfsSz(TreeNode* node){

        if(!node) return 0;
        int left = dfsSz(node->left);
        int right = dfsSz(node->right);
        sz[node] = left + right + 1;
        return sz[node];
    }

    double dfsRes(TreeNode* node){

        if(!node) return 0;
        double left = dfsRes(node->left);
        double right = dfsRes(node->right);
        return max(max(left, right), (double)sum[node] / sz[node]);
    }
};


int main() {

    return 0;
}