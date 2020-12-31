/// Source : https://leetcode.com/problems/range-sum-of-bst/
/// Author : liuyubobobo
/// Time   : 2018-11-11

#include <iostream>
#include <stack>

using namespace std;


/// Non-Recursion, using stack
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

        int res = 0;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()){
            TreeNode* cur = stack.top();
            stack.pop();

            if(!cur) continue;

            if(L <= cur->val && cur->val <= R){
                res += cur->val;
                stack.push(cur->right);
                stack.push(cur->left);
            }
            else if(cur->val < L)
                stack.push(cur->right);
            else
                stack.push(cur->left);
        }
        return res;
    }
};


int main() {

    return 0;
}