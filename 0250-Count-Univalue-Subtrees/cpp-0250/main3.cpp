/// Source : https://leetcode.com/problems/count-univalue-subtrees/description/
/// Author : liuyubobobo
/// Time   : 2018-06-02

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
/// Use class variable to store the result
/// Time Complexity: O(n)
/// Space Complexty: O(h)
class Solution {

private:
    int result = 0;

public:
    int countUnivalSubtrees(TreeNode* root) {

        if(root) dfs(root);
        return result;
    }

private:
    bool dfs(TreeNode* node){

        bool ok = true;
        if(node->left){
            bool isLeft = dfs(node->left);
            if(!isLeft || node->val != node->left->val) ok = false;
        }

        if(node->right){
            bool isRight = dfs(node->right);
            if(!isRight || node->val != node->right->val) ok = false;
        }

        if(ok) result ++;
        return ok;
    }
};


int main() {

    return 0;
}