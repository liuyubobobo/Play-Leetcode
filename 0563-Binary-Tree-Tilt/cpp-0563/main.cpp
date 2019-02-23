/// Source : https://leetcode.com/problems/binary-tree-tilt/
/// Author : liuyubobobo
/// Time   : 2019-02-23

#include <iostream>

using namespace std;


/// Recursive Simulation
/// Time Complexity: O(n^2)
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
    int findTilt(TreeNode* root) {

        if(!root) return 0;
        return abs(sum(root->left) - sum(root->right)) + findTilt(root->left) + findTilt(root->right);
    }

private:
    int sum(TreeNode* root){

        if(!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
};


int main() {

    return 0;
}