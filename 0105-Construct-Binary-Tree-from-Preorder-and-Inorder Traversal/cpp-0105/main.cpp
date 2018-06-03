/// Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
/// Author : liuyubobobo
/// Time   : 2018-06-03

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Recursive
/// Time Complexity: O(n*h) where n is the num of node in th tree
///                         and h is the height of the tree
/// Space Complexity: O(h)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

private:
    TreeNode* buildTree(const vector<int>& preorder, int preorderL, int preorderR,
                        const vector<int>& inorder, int inorderL, int inorderR){

        if(inorderL >= inorderR){
            assert(preorderL >= preorderR);
            return NULL;
        }

        if(inorderL + 1 == inorderR){
            assert(preorderL + 1 == preorderR);
            return new TreeNode(inorder[inorderL]);
        }

        TreeNode* root = new TreeNode(preorder[preorderL]);
        int rootPos = find(inorder.begin() + inorderL, inorder.begin() + inorderR, root->val) - inorder.begin();
        assert(rootPos >= inorderL && rootPos < inorderR);

        int lsize = rootPos - inorderL;
        int rsize = inorderR - (rootPos + 1);
        root->left = buildTree(preorder, preorderL + 1, preorderL + 1 + lsize, inorder, inorderL, rootPos);
        root->right = buildTree(preorder, preorderL + 1 + lsize, preorderR, inorder, rootPos + 1, inorderR);
        return root;
    }
};


int main() {

    return 0;
}