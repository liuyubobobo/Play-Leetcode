/// Source : https://leetcode.com/problems/find-mode-in-binary-search-tree/
/// Author : liuyubobobo
/// Time   : 2019-07-25

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Inorder Traversal
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

private:
    vector<int> inorder;

public:
    vector<int> findMode(TreeNode* root) {

        dfs(root);

        vector<int> res;
        int best = 0;
        for(int start = 0, i = 1; i <= inorder.size(); i ++)
            if(i == inorder.size() || inorder[i] != inorder[start]){
                if(i - start > best)
                    best = i - start, res = {inorder[start]};
                else if(i - start == best)
                    res.push_back(inorder[start]);
                start = i;
                i = start;
            }

        return res;
    }

private:
    void dfs(TreeNode* node){

        if(node){
            dfs(node->left);
            inorder.push_back(node->val);
            dfs(node->right);
        }
    }
};


int main() {

    // [3,2,3,null,null,3,4,null,null,4,5,null,null,5,6]
    // 3
    return 0;
}