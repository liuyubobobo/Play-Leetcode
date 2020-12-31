/// Source : https://leetcode.com/problems/count-univalue-subtrees/description/
/// Author : liuyubobobo
/// Time   : 2019-03-02

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
/// Treat null as univalue subtree and make the implementation much more concise :-)
///
/// Time Complexity: O(n)
/// Space Complexty: O(h)
class Solution {

private:
    int result = 0;

public:
    int countUnivalSubtrees(TreeNode* root) {

        dfs(root);
        return result;
    }

private:
    bool dfs(TreeNode* node){

        if(!node) return true;

        bool isLeft = dfs(node->left), isRight = dfs(node->right);
        bool ok = isLeft && (!node->left || node->val == node->left->val) &&
                  isRight && (!node->right || node->val == node->right->val);

        if(ok) result ++;
        return ok;
    }
};


int main() {

//      5
//     / \
//    1  5
//   / \  \
//  5  5  5
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(5);
    cout << Solution().countUnivalSubtrees(root) << endl;

    return 0;
}