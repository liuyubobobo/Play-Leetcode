/// Source : https://leetcode.com/problems/sum-of-left-leaves/
/// Author : liuyubobobo
/// Time   : 2019-04-22

#include <iostream>

using namespace std;


/// Recursion
/// Don't use class member variable
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

public:
    int sumOfLeftLeaves(TreeNode* root) {

        if(!root) return 0;

        return dfs(root, false);
    }

private:
    int dfs(TreeNode* node, bool isLeft){

        if(!node->left && !node->right){
            if(isLeft) return node->val;
            return 0;
        }

        int res = 0;
        if(node->left) res += dfs(node->left, true);
        if(node->right) res += dfs(node->right, false);
        return res;
    }
};


int main() {

    return 0;
}