/// Source : https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
/// Author : liuyubobobo
/// Time   : 2020-01-11

#include <iostream>
#include <vector>

using namespace std;


/// Inorder DFS and Merge
/// Time Complexity: O(m + n)
/// Space Complexity: O(m + n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        vector<int> res1, res2;
        dfs(root1, res1);
        dfs(root2, res2);

        vector<int> res;
        int i = 0, j = 0;
        while(i < res1.size() && j < res2.size()){
            if(res1[i] < res2[j]) res.push_back(res1[i ++]);
            else res.push_back(res2[j ++]);
        }
        while(i < res1.size()) res.push_back(res1[i ++]);
        while(j < res2.size()) res.push_back(res2[j ++]);
        return res;
    }

private:
    void dfs(TreeNode* node, vector<int>& res){

        if(!node) return;
        dfs(node->left, res);
        res.push_back(node->val);
        dfs(node->right, res);
    }
};


int main() {

    return 0;
}
