/// Source : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
/// Author : liuyubobobo
/// Time   : 2020-10-17

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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

private:
    unordered_map<TreeNode*, int> sum_table, max_table, min_table;
    unordered_map<TreeNode*, bool> isBST;

public:
    int maxSumBST(TreeNode* root) {

        dfs(root);

        int res = 0;
        for(const pair<TreeNode*, int>& p: sum_table)
            if(isBST[p.first]) res = max(res, p.second);
        return res;
    }

private:
    void dfs(TreeNode* node){

        if(!node) return;

        dfs(node->left);
        dfs(node->right);

        int sum = node->val, maxv = node->val, minv = node->val;
        if(node->left)
            sum += sum_table[node->left],
            maxv = max(maxv, max_table[node->left]),
            minv = min(minv, min_table[node->left]);
        if(node->right)
            sum += sum_table[node->right],
            maxv = max(maxv, max_table[node->right]),
            minv = min(minv, min_table[node->right]);

        sum_table[node] = sum;
        max_table[node] = maxv;
        min_table[node] = minv;

        bool ok = true;
        if(node->left && node->val <= max_table[node->left]) ok = false;
        if(node->left && !isBST[node->left]) ok = false;
        if(node->right && node->val >= min_table[node->right]) ok = false;
        if(node->right && !isBST[node->right]) ok = false;
        isBST[node] = ok;

        return;
    }
};


int main() {

    return 0;
}
