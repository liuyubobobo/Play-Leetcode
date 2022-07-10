/// Source : https://leetcode.com/problems/evaluate-boolean-binary-tree/
/// Author : liuyubobobo
/// Time   : 2022-07-09

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
    bool evaluateTree(TreeNode* root) {

        if(root->left == nullptr || root->right == nullptr)
            return root->val;

        int a = evaluateTree(root->left);
        int b = evaluateTree(root->right);

        if(root->val == 2) return a | b;
        return a & b;
    }
};


int main() {

    return 0;
}
