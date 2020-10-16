/// Source : https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/
/// Author : liuyubobobo
/// Time   : 2020-10-15

#include <iostream>
#include <queue>

using namespace std;


/// BFS, one queue and using null as sentinel
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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){

            TreeNode* cur = q.front();
            q.pop();

            if(cur == u) return q.front();
            else if(cur == nullptr) q.push(nullptr);
            else{
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return nullptr;
    }
};


int main() {

    return 0;
}
