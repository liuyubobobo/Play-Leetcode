/// Source : https://leetcode.com/problems/path-sum-iii/description/
/// Author : liuyubobobo
/// Time   : 2017-11-18

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
/// Time Complexity: O(n^2), where n is the node's number of the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {

public:
    int pathSum(TreeNode* root, int sum) {

        if(root == NULL)
            return 0;

        return findPath(root, sum)
                + pathSum(root->left , sum)
                + pathSum(root->right , sum);
    }

private:
    int findPath(TreeNode* node, int num){

        if(node == NULL)
            return 0;

        int res = 0;
        if(node->val == num)
            res += 1;

        res += findPath(node->left , num - node->val);
        res += findPath(node->right , num - node->val);

        return res;
    }
};

int main() {

    /*****************
     * Test case:
     *
     *       10
     *      /  \
     *     5   -3
     *    / \    \
     *   3   2   11
     *  / \   \
     * 3  -2   1
     *****************/
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(-2);

    TreeNode* node3 = new TreeNode(3);
    node3->left = node1;
    node3->right = node2;

    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(2);
    node5->right = node4;

    TreeNode* node6 = new TreeNode(5);
    node6->left = node3;
    node6->right = node5;

    TreeNode* node7 = new TreeNode(11);
    TreeNode* node8 = new TreeNode(-3);
    node8->right = node7;

    TreeNode* node9 = new TreeNode(10);
    node9->left = node6;
    node9->right = node8;

    cout << Solution().pathSum(node9, 8) << endl;

    return 0;
}
