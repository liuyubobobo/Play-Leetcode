/// Source : https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
/// Author : liuyubobobo
/// Time   : 2020-03-14

#include <iostream>
#include <stack>

using namespace std;


/// Non-Recursion
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        stack<TreeNode*> stack1, stack2;
        stack1.push(original);
        stack2.push(cloned);
        while(!stack1.empty()){
            TreeNode* node1 = stack1.top(); stack1.pop();
            TreeNode* node2 = stack2.top(); stack2.pop();

            if(node1 == target) return node2;

            if(node1->left) stack1.push(node1->left), stack2.push(node2->left);
            if(node1->right) stack1.push(node1->right), stack2.push(node2->right);
        }
        return NULL;
    }
};


int main() {

    return 0;
}
