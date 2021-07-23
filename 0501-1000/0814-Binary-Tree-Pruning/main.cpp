/// Source : https://cses.fi/problemset/task/1666/
/// Author : liuyubobobo
/// Time   : 2021-07-12

#include <iostream>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {

        bool contain_one;
        return pruneTree(root, contain_one);
    }

private:
    TreeNode* pruneTree(TreeNode* root, bool& contain_one){

        if(root == NULL){
            contain_one = false;
            return NULL;
        }

        bool left_contain_one = true;
        root->left = pruneTree(root->left, left_contain_one);

        bool right_contain_one = true;
        root->right = pruneTree(root->right, right_contain_one);

        contain_one = (root->val == 1 || left_contain_one || right_contain_one);
        if(contain_one)
            return root;
        return NULL;
    }
};

int main() {

    return 0;
}
