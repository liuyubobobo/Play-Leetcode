/// Source : https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/
/// Author : liuyubobobo
/// Time   : 2021-08-20

#include <iostream>

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
    int res = 0;

public:
    int equalToDescendants(TreeNode* root) {

        res = 0;
        dfs(root);
        return res;
    }

private:
    long long dfs(TreeNode* node){

        if(!node) return 0;

        long long a = dfs(node->left), b = dfs(node->right);
        res += ((long long)node->val == a + b);
        return a + b + node->val;
    }
};


int main() {

    return 0;
}
