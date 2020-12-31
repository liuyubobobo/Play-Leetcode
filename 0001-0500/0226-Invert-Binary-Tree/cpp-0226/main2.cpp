/// Source : https://leetcode.com/problems/invert-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2017-11-17

#include <iostream>
#include <queue>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Non-Recursive
/// Time Complexity: O(n), where n is the node's number of the tree
/// Space Complexity: O(n)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL)
            return NULL;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            swap(curNode->left, curNode->right);

            if(curNode->left)
                q.push(curNode->left);
            if(curNode->right)
                q.push(curNode->right);
        }

        return root;
    }
};

int main() {

    return 0;
}