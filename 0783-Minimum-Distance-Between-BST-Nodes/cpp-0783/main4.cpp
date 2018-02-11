/// Source : https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
/// Author : liuyubobobo
/// Time   : 2010-02-11

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

/// Inorder Traverse
/// Inorder traverse the tree and record every neighbor numbers diff during the process.
///
/// Time Complexity: O(n)
/// Space Complexity: O(logn)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

private:
    int* lastNumber;

public:
    int minDiffInBST(TreeNode* root) {

        int res = INT_MAX;
        lastNumber = NULL;
        dfs(root, res);

        return res;
    }

private:
    void dfs(TreeNode* node, int& res){

        if(node == NULL)
            return;

        dfs(node->left, res);

        if(lastNumber != NULL){
            // cout << node->val << " " << (*lastNumber) << endl;
            res = min(res, node->val - *lastNumber);
        }

        lastNumber = &(node->val);

        dfs(node->right, res);
    }
};

int main() {

    // [90,69,null,49,89,null,52,null,null,null,null]

    // [27,null,34,null,58,50,null,44,null,null,null]
    TreeNode* node44 = new TreeNode(44);
    TreeNode* node50 = new TreeNode(50);
    TreeNode* node58 = new TreeNode(58);
    TreeNode* node34 = new TreeNode(34);
    TreeNode* node27 = new TreeNode(27);

    node27->right = node34;
    node34->right = node58;
    node58->left = node50;
    node50->left = node44;

    cout << Solution().minDiffInBST(node27);

    return 0;
}