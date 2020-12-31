/// Source : https://leetcode.com/problems/build-binary-expression-tree-from-infix-expression/
/// Author : liuyubobobo
/// Time   : 2020-10-15

#include <iostream>
#include <vector>

using namespace std;


/// Inoder to store all the elements
/// Time Complexity: init: O(n)
///                  others: O(1)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {

private:
    vector<int> v;
    int p = -1;

public:
    BSTIterator(TreeNode* root): v(), p(-1) {
        inorder(root);
    }

    bool hasNext() {
        return p + 1 < v.size();
    }

    int next() {
        return v[++p];
    }

    bool hasPrev() {
        return p - 1 >= 0;
    }

    int prev() {
        return v[--p];
    }

private:
    void inorder(TreeNode* node){

        if(!node) return;
        inorder(node->left);
        v.push_back(node->val);
        inorder(node->right);
    }
};


int main() {

    return 0;
}
