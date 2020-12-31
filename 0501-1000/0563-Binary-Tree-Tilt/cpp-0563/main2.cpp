/// Source : https://leetcode.com/problems/binary-tree-tilt/
/// Author : liuyubobobo
/// Time   : 2019-02-23

#include <iostream>

using namespace std;


/// Recursive and use class variable to record the result
/// Time Complexity: O(n)
/// Space Complexity: O(h)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {

private:
    int result;

public:
    int findTilt(TreeNode* root) {

        result = 0;
        dfs(root);
        return result;
    }

private:
    int dfs(TreeNode* root){

        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        result += abs(left - right);
        return root->val + left + right;
    }
};


int main() {

    return 0;
}