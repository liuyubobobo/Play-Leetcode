/// Source : https://leetcode.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;
        if(!root) return res;

        vector<TreeNode*> cur = {root};
        while(cur.size()){
            res.push_back(cur.back()->val);

            vector<TreeNode*> next;
            for(TreeNode* node: cur){
                if(node->left) next.push_back(node->left);
                if(node->right) next.push_back(node->right);
            }
            cur = next;
        }
        return res;
    }
};


int main() {

    return 0;
}