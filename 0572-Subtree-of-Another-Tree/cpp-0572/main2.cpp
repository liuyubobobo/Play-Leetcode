/// Source : https://leetcode.com/problems/subtree-of-another-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-10-16

#include <iostream>

using namespace std;


/// Recursion
/// Time Complexity: O(m * n)
/// Space Complexity: O(logm)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {

        if(!s && !t)
            return true;

        if(equal(s, t))
            return true;

        if(s && isSubtree(s->left, t))
            return true;

        if(s && isSubtree(s->right, t))
            return true;

        return false;
    }

private:
    bool equal(TreeNode* a, TreeNode* b){

        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val != b->val) return false;
        return equal(a->left, b->left) && equal(a->right, b->right);
    }
};


int main() {

    return 0;
}