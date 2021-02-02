/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-15

#include <iostream>
#include <vector>

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {

        root = trim(root, low, high);
        return root;
    }

private:
    TreeNode* trim(TreeNode* node, int low, int high){

        if(!node) return NULL;
        if(node->val < low) return trim(node->right, low, high);
        if(node->val > high) return trim(node->left, low, high);

        node->left = trim(node->left, low, high);
        node->right = trim(node->right, low, high);
        return node;
    }
};


int main() {

    return 0;
}
