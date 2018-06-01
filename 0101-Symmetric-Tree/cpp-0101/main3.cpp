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
/// Using two queues to level traverse the root in different directions
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if(root == NULL)
            return true;

        queue<TreeNode*> q1, q2;
        q1.push(root);
        q2.push(root);
        while(!q1.empty() && !q2.empty()){
            TreeNode* node1 = q1.front();
            q1.pop();

            TreeNode* node2 = q2.front();
            q2.pop();

            if(node1 == NULL && node2 == NULL)
                continue;

            if(node1 == NULL || node2 == NULL)
                return false;

            if(node1->val != node2->val)
                return false;

            q1.push(node1->left);
            q1.push(node1->right);

            q2.push(node2->right);
            q2.push(node2->left);
        }

        return q1.empty() && q2.empty();
    }
};


int main() {

    return 0;
}