/// Source : https://leetcode.com/problems/count-univalue-subtrees/description/
/// Author : liuyubobobo
/// Time   : 2019-03-03

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
/// Pass parent value to make the implementation even more concise :-)
///
/// Time Complexity: O(n)
/// Space Complexty: O(h)
class Solution {

private:
    int result = 0;

public:
    int countUnivalSubtrees(TreeNode* root) {

        dfs(root, NULL);
        return result;
    }

private:
    bool dfs(TreeNode* node, TreeNode* parent){

        if(!node) return true;

        bool isLeft = dfs(node->left, node), isRight = dfs(node->right, node);
        if(!isLeft || !isRight) return false;

        result ++;
        return parent && node->val == parent->val;
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