/// Source : https://leetcode.com/problems/path-sum/description/
/// Author : liuyubobobo
/// Time   : 2018-11-17

#include <iostream>
#include <stack>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Non-Recursive
/// Using Stack
///
/// Time Complexity: O(n), where n is the nodes' number of the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {

        if(!root)
            return false;

        stack<pair<TreeNode*, int>> stack;
        stack.push(make_pair(root, sum));
        while(!stack.empty()){
            TreeNode* cur = stack.top().first;
            int num = stack.top().second;
            stack.pop();

            if(num == cur->val && !cur->left && !cur->right)
                return true;

            if (cur->left)
                stack.push(make_pair(cur->left, num - cur->val));
            if (cur->right)
                stack.push(make_pair(cur->right, num - cur->val));
        }
        return false;
    }
};


int main() {

    return 0;
}