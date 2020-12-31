/// Source : https://leetcode.com/contest/weekly-contest-117/problems/univalued-binary-tree/
/// Author : liuyubobobo
/// Time   : 2019-03-17

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
/// Space Complexity: O(h)
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {

        if(!root) return true;

        int v = root->val;
        return dfs(root, v);
    }

private:
    bool dfs(TreeNode* root, int v){

        if(!root) return true;
        return root->val == v && dfs(root->left, v) && dfs(root->right, v);
    }
};


int main() {

    return 0;
}