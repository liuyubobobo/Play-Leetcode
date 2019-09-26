/// Source : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
/// Author : liuyubobobo
/// Time   : 2019-09-26

#include <iostream>
#include <vector>

using namespace std;


/// BFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;
        if(!root) return res;

        vector<TreeNode*> cur;
        cur.push_back(root);
        int index = 0;
        while(cur.size()){

            vector<TreeNode*> next;
            vector<int> tres;

            for(TreeNode* node: cur){
                tres.push_back(node->val);
                if(node->left) next.push_back(node->left);
                if(node->right) next.push_back(node->right);
            }

            if(index % 2) reverse(tres.begin(), tres.end());
            res.push_back(tres);

            cur = next;
            index ++;
        }
        return res;
    }
};


int main() {

    return 0;
}