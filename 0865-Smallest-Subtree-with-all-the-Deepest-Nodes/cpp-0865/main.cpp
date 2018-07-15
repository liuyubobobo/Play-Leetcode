/// Source : https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
/// Author : liuyubobobo
/// Time   : 2018-07-07

#include <iostream>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Recursion
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int deepest;
    TreeNode* res;

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        res = NULL;
        deepest = -1;
        getRes(root, 0);
        return res;
    }

private:
    int getRes(TreeNode* node, int depth){

        if(node == NULL)
            return depth - 1;

        if(depth > deepest){
            res = node;
            deepest = depth;
        }

        int dl = getRes(node->left, depth + 1);
        int dr = getRes(node->right, depth + 1);

        if(dl == dr && dl == deepest)
            res = node;

        return max(dl, dr);
    }
};


int main() {

    cout << Solution().subtreeWithAllDeepest(new TreeNode(1))->val << endl;

    return 0;
}