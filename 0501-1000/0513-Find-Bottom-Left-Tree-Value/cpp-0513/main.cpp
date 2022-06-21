/// Source : https://leetcode.com/problems/find-bottom-left-tree-value/
/// Author : liuyubobobo
/// Time   : 2022-06-21

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

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
    int findBottomLeftValue(TreeNode* root) {

        int res = -1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            res = q.front()->val;
            queue<TreeNode*> tq;
            while(!q.empty()){
                TreeNode* node = q.front(); q.pop();
                if(node->left) tq.push(node->left);
                if(node->right) tq.push(node->right);
            }
            q = tq;
        }
        return res;
    }
};


int main() {

    return 0;
}
