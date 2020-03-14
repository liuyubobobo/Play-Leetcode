/// Source : https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
/// Author : liuyubobobo
/// Time   : 2020-03-14

#include <iostream>
#include <stack>

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
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        if(original == target) return cloned;
        if(!original) return NULL;

        TreeNode* node1 = getTargetCopy(original->left, cloned->left, target);
        return node1 ? node1 : getTargetCopy(original->right, cloned->right, target);
    }
};


int main() {

    return 0;
}
