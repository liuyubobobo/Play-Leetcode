/// Source : https://leetcode.com/problems/minimum-depth-of-binary-tree/
/// Author : liuyubobobo
/// Time   : 2018-10-29

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
/// Using stack
///
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {
public:
    int minDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        stack<pair<TreeNode*, int>> stack;
        stack.push(make_pair(root, 1));
        int res = INT_MAX;
        while(!stack.empty()){
            TreeNode* cur = stack.top().first;
            int step = stack.top().second;
            stack.pop();

            if(!cur->left && !cur->right)
                res = min(res, step);
            else{
                if(cur->left)
                    stack.push(make_pair(cur->left, step + 1));
                if(cur->right)
                    stack.push(make_pair(cur->right, step + 1));
            }
        }
        return res;
    }
};


int main() {

    return 0;
}