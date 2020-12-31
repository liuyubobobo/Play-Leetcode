/// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-12-16

#include <iostream>
#include <cassert>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Non-Recursive
/// Time Complexity: O(lgn), where n is the node's number of the tree
/// Space Complexity: O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root) return root;

        TreeNode* cur = root;
        while(cur) {
            if (p->val < cur->val && q->val < cur->val)
                cur = cur->left;
            else if (p->val > cur->val && q->val > cur->val)
                cur = cur->right;
            else
                return cur;
        }

        return NULL;
    }
};

int main() {

    return 0;
}