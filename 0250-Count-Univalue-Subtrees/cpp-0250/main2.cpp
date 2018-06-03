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
/// Time Complexity: O(n)
/// Space Complexty: O(h)
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {

        if(root == NULL)
            return 0;

        return dfs(root).second;
    }

private:
    pair<bool, int> dfs(TreeNode* root){

        pair<bool, int> leftRes, rightRes;
        int res = 0;
        bool isUnivalTree = true;

        if(root->left != NULL) {
            leftRes = dfs(root->left);
            res += leftRes.second;
            isUnivalTree = isUnivalTree && leftRes.first && root->val == root->left->val;
        }

        if(root->right != NULL) {
            rightRes = dfs(root->right);
            res += rightRes.second;
            isUnivalTree = isUnivalTree && rightRes.first && root->val == root->right->val;
        }

        if(isUnivalTree)
            res += 1;

        return make_pair(isUnivalTree, res);
    }
};


int main() {

    return 0;
}