/// Source : https://leetcode.com/problems/sum-of-left-leaves/
/// Author : liuyubobobo
/// Time   : 2019-04-22

#include <iostream>

using namespace std;


/// Recursion
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
    int res = 0;

public:
    int sumOfLeftLeaves(TreeNode* root) {

        if(!root) return 0;

        dfs(root, false);
        return res;
    }

private:
    void dfs(TreeNode* node, bool isLeft){

        if(!node->left && !node->right){
            if(isLeft) res += node->val;
            return;
        }

        if(node->left) dfs(node->left, true);
        if(node->right) dfs(node->right, false);
    }
};


int main() {

    return 0;
}