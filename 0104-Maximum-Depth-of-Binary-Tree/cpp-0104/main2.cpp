/// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2017-11-17

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

/// Non-recursive
/// Time Complexity: O(n), where n is the nodes' number in the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        stack<pair<TreeNode*, int>> s;
        s.push(make_pair(root, 1));
        int res = 0;
        while(!s.empty()){
            TreeNode* curNode = s.top().first;
            int depth = s.top().second;
            s.pop();

            if(curNode->left == NULL && curNode->right == NULL)
                res = max(res, depth);
            else{
                if(curNode->left)
                    s.push(make_pair(curNode->left, depth + 1));
                if(curNode->right)
                    s.push(make_pair(curNode->right, depth + 1));
            }
        }

        return res;
    }
};

int main() {

    return 0;
}