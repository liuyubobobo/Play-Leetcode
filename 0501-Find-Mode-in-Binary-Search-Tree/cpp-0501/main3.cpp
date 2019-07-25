/// Source : https://leetcode.com/problems/find-mode-in-binary-search-tree/
/// Author : liuyubobobo
/// Time   : 2019-07-25

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Inorder Traversal and record result online
/// Time Complexity: O(n)
/// Space Complexity: O(h)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

private:
    vector<int> res;
    int best = 1;
    int count = 0;
    TreeNode* pre = NULL;

public:
    vector<int> findMode(TreeNode* root) {

        if(!root) return {};
        dfs(root);
        if(count > best) best = count, res = {pre->val};
        else if(count == best) res.push_back(pre->val);

        return res;
    }

private:
    void dfs(TreeNode* node){

        if(node){
            dfs(node->left);

            if(!pre || node->val == pre->val) count ++;
            else{
                if(count > best) best = count, res = {pre->val};
                else if(count == best) res.push_back(pre->val);
                count = 1;
            }
            pre = node;

            dfs(node->right);
        }
    }
};


int main() {

    // [3,2,3,null,null,3,4,null,null,4,5,null,null,5,6]
    // 3
    return 0;
}