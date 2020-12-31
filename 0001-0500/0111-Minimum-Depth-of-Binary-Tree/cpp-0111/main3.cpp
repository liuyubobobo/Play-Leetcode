/// Source : https://leetcode.com/problems/minimum-depth-of-binary-tree/
/// Author : liuyubobobo
/// Time   : 2018-10-29

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Non-Recursive
/// Using BFS may not visit all the nodes :-)
///
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {
public:
    int minDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        queue<pair<TreeNode*, int>> queue;
        queue.push(make_pair(root, 1));
        while(!queue.empty()){
            TreeNode* cur = queue.front().first;
            int step = queue.front().second;
            queue.pop();

            if(!cur->left && !cur->right)
                return step;
            else{
                if(cur->left)
                    queue.push(make_pair(cur->left, step + 1));
                if(cur->right)
                    queue.push(make_pair(cur->right, step + 1));
            }
        }

        assert(false);
        return -1;
    }
};


int main() {

    return 0;
}