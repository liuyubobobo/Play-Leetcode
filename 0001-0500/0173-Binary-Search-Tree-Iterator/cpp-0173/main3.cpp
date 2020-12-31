/// Source : https://leetcode.com/problems/binary-search-tree-iterator/description/
/// Author : liuyubobobo
/// Time   : 2018-06-06

#include <iostream>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

/// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Using Classic Non-recursive Inorder Traversal Algorithm
///
/// Time Complexity: initial: O(h)
///                  hasNext: O(1)
///                  next: O(h)
/// Space Complexity: O(h)
class BSTIterator {

private:
    stack<TreeNode*> myStack;

public:
    BSTIterator(TreeNode *root) {

        TreeNode* node = root;
        while(node != NULL){
            myStack.push(node);
            node = node->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {

        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {

        assert(hasNext());
        TreeNode* retNode = myStack.top();
        myStack.pop();

        TreeNode* node = retNode->right;
        while(node != NULL){
            myStack.push(node);
            node = node->left;
        }

        return retNode->val;
    }
};


int main() {

    return 0;
}