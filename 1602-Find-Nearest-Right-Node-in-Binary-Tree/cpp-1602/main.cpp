/// Source : https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/
/// Author : liuyubobobo
/// Time   : 2020-10-15

#include <iostream>
#include <vector>

using namespace std;


/// BFS, two queues
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

        vector<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){

            for(int i = 0; i < q.size(); i ++)
                if(q[i] == u) return i == q.size() - 1 ? nullptr : q[i + 1];

            vector<TreeNode*> q2;
            for(TreeNode* node: q){
                if(node->left) q2.push_back(node->left);
                if(node->right) q2.push_back(node->right);
            }
            q = q2;
        }
        return nullptr;
    }
};


int main() {

    return 0;
}
