/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-05-22

#include <iostream>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// InOrder traverse
/// validate during the traversing
///
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {

private:
    int pre = -1;
    bool isPre = false;

public:
    bool isValidBST(TreeNode* root) {

        isPre = false;
        pre = -1;
        return inOrder(root);
    }

private:
    bool inOrder(TreeNode* node){

        if(node == NULL)
            return true;

        if(!inOrder(node->left))
            return false;

        if(isPre && pre >= node->val)
            return false;
        isPre = true;
        pre = node->val;

        if(!inOrder(node->right))
            return false;

        return true;
    }
};

int main() {

    return 0;
}