/// Source : https://leetcode.com/problems/range-sum-of-bst/
/// Author : liuyubobobo
/// Time   : 2018-11-10

#include <iostream>

using namespace std;


/// Recursion
/// Time Complexity: O(n)
/// Space Complexity: O(h)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {

        return sum(root, L, R);
    }

private:
    int sum(TreeNode* node, int L, int R){

        if(!node)
            return 0;

        if(node->val < L)
            return sum(node->right, L, R);

        if(node->val > R)
            return sum(node->left, L, R);

        int res = node->val;
        res += sum(node->left, L, node->val - 1);
        res += sum(node->right, node->val + 1, R);
        return res;
    }
};


int main() {

    return 0;
}