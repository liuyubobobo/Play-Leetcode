/// Source : https://leetcode.com/problems/path-sum-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-10-16

#include <iostream>
#include <vector>

using namespace std;


/// Recursion
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<vector<int>> res;
        if(!root)
            return res;

        vector<int> tres;
        dfs(root, tres, 0, sum, res);
        return res;
    }

private:
    void dfs(TreeNode* node, vector<int>& tres, int tsum,
             int sum, vector<vector<int>>& res){

        tres.push_back(node->val);
        tsum += node->val;

        if(!node->left && !node->right){
            if(tsum == sum)
                res.push_back(tres);
        }
        else {
            if (node->left)
                dfs(node->left, tres, tsum, sum, res);

            if (node->right)
                dfs(node->right, tres, tsum, sum, res);
        }

        tres.pop_back();
        return;
    }
};


int main() {

    return 0;
}