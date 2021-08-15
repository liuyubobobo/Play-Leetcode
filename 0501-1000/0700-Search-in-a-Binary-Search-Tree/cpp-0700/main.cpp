/// Source : https://leetcode.com/problems/search-in-a-binary-search-tree/
/// Author : liuyubobobo
/// Time   : 2021-08-15

#include <iostream>

using namespace std;


/// DFS
/// Time Complexity: O(h)
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
    TreeNode* searchBST(TreeNode* root, int val) {

        if(!root) return nullptr;
        if(root->val == val) return root;

        return val < root->val ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};


int main() {

    return 0;
}
