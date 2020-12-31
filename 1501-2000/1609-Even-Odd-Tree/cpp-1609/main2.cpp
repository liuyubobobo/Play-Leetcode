/// Source : https://leetcode.com/problems/even-odd-tree/
/// Author : liuyubobobo
/// Time   : 2020-10-04

#include <iostream>
#include <vector>
#include <vector>

using namespace std;


/// Simulation with BFS
/// Can stop early
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
    bool isEvenOddTree(TreeNode* root) {

        if(root->val % 2 == 0) return false;

        vector<TreeNode*> q = {root};
        int level = 0;

        while(!q.empty()){

            level ++;
            vector<TreeNode*> q2;
            for(TreeNode* node: q){
                if(node->left && !deal(level, q2, node->left)) return false;
                if(node->right && !deal(level, q2, node->right)) return false;
            }
            q = q2;
        }
        return true;
    }

private:
    bool deal(int level, vector<TreeNode*>& q2, TreeNode* node){
        if(level % 2 == node->val % 2) return false;
        if(!q2.empty() && level % 2 && node->val >= q2.back()->val) return false;
        if(!q2.empty() && level % 2 == 0 && node->val <= q2.back()->val) return false;
        q2.push_back(node);
        return true;
    }
};


int main() {

    return 0;
}
