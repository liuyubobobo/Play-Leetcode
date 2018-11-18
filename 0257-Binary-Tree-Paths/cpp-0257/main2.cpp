/// Source : https://leetcode.com/problems/binary-tree-paths/description/
/// Author : liuyubobobo
/// Time   : 2018-11-17

#include <iostream>
#include <string>
#include <vector>
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
/// Time Complexity: O(n), where n is the node's number in the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> res;
        if(root == NULL)
            return res;

        stack<pair<TreeNode*, string>> stack;
        stack.push(make_pair(root, to_string(root->val)));
        while(!stack.empty()){
            TreeNode* cur = stack.top().first;
            string s = stack.top().second;
            stack.pop();

            if(!cur->left && !cur->right)
                res.push_back(s);

            if(cur->left)
                stack.push(make_pair(cur->left, s + "->" + to_string(cur->left->val)));
            if(cur->right)
                stack.push(make_pair(cur->right, s + "->" + to_string(cur->right->val)));
        }
        return res;
    }
};


int main() {

    return 0;
}