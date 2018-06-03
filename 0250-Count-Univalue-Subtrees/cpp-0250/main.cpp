/// Source : https://leetcode.com/problems/count-univalue-subtrees/description/
/// Author : liuyubobobo
/// Time   : 2018-06-02
#include <iostream>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Recursive
/// Time Complexity: O(n^2)
/// Space Complexty: O(h)
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {

        if(root == NULL)
            return 0;

        int res = 0;
        if(root->left != NULL)
            res += countUnivalSubtrees(root->left);

        if(root->right != NULL)
            res += countUnivalSubtrees(root->right);

        if(isUnivalTree(root, root->val))
            res += 1;

        return res;
    }

private:
    bool isUnivalTree(TreeNode* root, int val){

        if(root == NULL)
            return true;

        if(root->val != val)
            return false;

        return isUnivalTree(root->left, val) && isUnivalTree(root->right, val);
    }
};


int main() {

    return 0;
}