/// Source : https://leetcode.com/problems/binary-tree-cameras/
/// Author : liuyubobobo
/// Time   : 2019-03-17

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    unordered_map<TreeNode*, int> indexes;

public:
    int minCameraCover(TreeNode* root) {

        if(!root) return 0;

        indexes.clear();
        tagIndexes(root, indexes);

        vector<int> dp(indexes.size() * 4, -1);
        return dfs(root, false, true, dp);
    }

private:
    int dfs(TreeNode* root, bool isCamera, bool needToCover, vector<int>& dp){

        if(!root) return 0;

        int index = indexes[root];
        int hashcode = index * 4 + isCamera * 2 + needToCover;

        if(dp[hashcode] != -1) return dp[hashcode];

        int res;
        if(isCamera){
            res = dfs(root->left, false, false, dp) + dfs(root->right, false, false, dp);
        }
        else{
            res = 1 + dfs(root->left, false, false, dp) + dfs(root->right, false, false, dp);
            if(!needToCover)
                res = min(res, dfs(root->left, false, true, dp) + dfs(root->right, false, true,dp));
            else{
                if(root->left)
                    res = min(res, 1 + dfs(root->left, true, false, dp) + dfs(root->right, false, true, dp));
                if(root->right)
                    res = min(res, 1 + dfs(root->right, true, false, dp) + dfs(root->left, false, true, dp));
                if(root->left && root->right)
                    res = min(res, 2 + dfs(root->left, true, false, dp) + dfs(root->right, true, false, dp));
            }
        }

        return dp[hashcode] = res;
    }

    void tagIndexes(TreeNode* root, unordered_map<TreeNode*, int>& indexes){

        if(!root) return;

        int index = indexes.size();
        indexes[root] = index;

        tagIndexes(root->left, indexes);
        tagIndexes(root->right, indexes);
    }
};

int main() {

    TreeNode* root1 = new TreeNode(0);
    root1->left = new TreeNode(0);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(0);
    cout << Solution().minCameraCover(root1) << endl;

    return 0;
}