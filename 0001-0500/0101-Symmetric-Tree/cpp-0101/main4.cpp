/// Source : https://leetcode.com/problems/symmetric-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-06-02

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
/// Using one queues to level traverse the root in different directions
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if(root == NULL)
            return true;

        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            TreeNode* node1 = q.front();
            q.pop();

            TreeNode* node2 = q.front();
            q.pop();

            if(node1 == NULL && node2 == NULL)
                continue;

            if(node1 == NULL || node2 == NULL)
                return false;

            if(node1->val != node2->val)
                return false;

            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }

        return true;
    }
};


int main() {

    return 0;
}