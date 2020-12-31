/// Source : https://leetcode.com/problems/house-robber-iii/description/
/// Author : liuyubobobo
/// Time   : 2017-12-09

#include <iostream>
#include <map>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Memory Search
/// Time Complexity: O(n), where n is the nodes' number in the tree
/// Space Complexity: O(n)
class Solution {

public:
    int rob(TreeNode* root) {
        return rob(root, true);
    }

private:
    int rob(TreeNode* root, bool include){

        if(root == NULL)
            return 0;

        int res = rob(root->left, true) + rob(root->right, true);
        if(include)
            res = max(root->val + rob(root->left, false) + rob(root->right, false),
                      res);

        return res;
    }
};

int main() {

    return 0;
}