/// Source : https://leetcode.com/problems/binary-search-tree-iterator/description/
/// Author : liuyubobobo
/// Time   : 2018-06-06

#include <iostream>
#include <vector>

using namespace std;

/// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Using an array to store all the elements
///
/// Time Complexity: initial: O(n)
///                  hasNext: O(1)
///                  next: O(1)
/// Space Complexity: O(n)
class BSTIterator {

private:
    vector<int> data;
    int nextIndex;

public:
    BSTIterator(TreeNode *root) {
        data.clear();
        inOrder(root);

        nextIndex = 0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return nextIndex < data.size();
    }

    /** @return the next smallest number */
    int next() {
        return data[nextIndex ++];
    }

private:
    void inOrder(TreeNode* node){

        if(node == NULL)
            return;

        inOrder(node->left);
        data.push_back(node->val);
        inOrder(node->right);
    }
};


int main() {

    return 0;
}