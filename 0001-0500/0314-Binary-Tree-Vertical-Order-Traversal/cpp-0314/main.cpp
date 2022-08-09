/// Source : https://leetcode.com/problems/binary-tree-vertical-order-traversal/
/// Author : liuyubobobo
/// Time   : 2022-08-08

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;


/// BFS + Map
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
    vector<vector<int>> verticalOrder(TreeNode* root) {

        if(root == nullptr) return {};

        map<int, vector<int>> table;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int col = q.front().second;
            q.pop();

            table[col].push_back(node->val);
            if(node->left) q.push({node->left, col - 1});
            if(node->right) q.push({node->right, col + 1});
        }

        vector<vector<int>> res;
        for(const pair<int, vector<int>>& p: table)
            res.push_back(p.second);
        return res;
    }
};


int main() {

    return 0;
}
