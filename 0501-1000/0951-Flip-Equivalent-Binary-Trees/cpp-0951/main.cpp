/// Source : https://leetcode.com/problems/flip-equivalent-binary-trees/
/// Author : liuyubobobo
/// Time   : 2018-12-01

#include <iostream>

using namespace std;


/// Recursion
/// Time Complexity: O(min(N1, N2))
/// Space Complexity: O(min(h1, h2))

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        return check(root1, root2);
    }

private:
    bool check(TreeNode* node1, TreeNode* node2){

        if(!node1 && !node2)
            return true;

        if(!node1 || !node2)
            return false;

        if(node1->val != node2->val)
            return false;

        return (check(node1->left, node2->left) && check(node1->right, node2->right)) ||
               (check(node1->right, node2->left) && check(node1->left, node2->right));
    }
};


int main() {

    return 0;
}