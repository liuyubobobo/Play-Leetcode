/// Source : https://leetcode.com/problems/check-completeness-of-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2018-12-15

#include <iostream>
#include <vector>

using namespace std;


/// Recursion
/// Time Complexity: O(n+)
/// Space Complexity: O(h)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        if(!root) return true;

        TreeNode* cur = root;
        int left = 0;
        while(cur)
            left ++, cur = cur->left;

        cur = root;
        int right = 0;
        while(cur)
            right ++, cur = cur->right;

        if(left < right) return false;
        if(left == right)
            return isFullTree(root->left, left - 1) && isFullTree(root->right, right - 1);
        if(left - right > 1) return false;
        return (isFullTree(root->left, left - 1) && isCompleteTree(root->right)) ||
               (isCompleteTree(root->left) && isFullTree(root->right, right - 1));
    }

private:
    bool isFullTree(TreeNode* root, int depth){
        if(!root)
            return depth == 0;
        return isFullTree(root->left, depth - 1) && isFullTree(root->right, depth - 1);
    }
};


int main() {

    return 0;
}