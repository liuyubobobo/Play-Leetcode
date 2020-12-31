/// Source : https://leetcode.com/problems/increasing-order-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-09-02

#include <iostream>
#include <vector>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Using Morris Treversal
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

private:
    TreeNode* cur;

public:
    TreeNode* increasingBST(TreeNode* root) {

        if(root == NULL)
            return NULL;

        TreeNode* dummyRoot = new TreeNode(-1);
        cur = dummyRoot;

        // Morris Traversal
        TreeNode* node = root;
        while(node){
            if(node->left == NULL){
                cur->right = node;
                cur = cur->right;
                cur->left = NULL;

                node = node->right;
            }
            else{
                TreeNode* prev = node->left;
                while(prev->right && prev->right != node)
                    prev = prev->right;

                if(prev->right == NULL){
                    prev->right = node;
                    node = node->left;
                }
                else{
                    prev->right = NULL;

                    cur->right = node;
                    cur = cur->right;
                    cur->left = NULL;

                    node = node->right;
                }
            }
        }

        TreeNode* ret = dummyRoot->right;
        delete dummyRoot;
        return ret;
    }
};


int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    Solution().increasingBST(root);

    return 0;
}