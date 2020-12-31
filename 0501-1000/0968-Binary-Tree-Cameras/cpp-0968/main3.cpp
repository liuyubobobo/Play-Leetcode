/// Source : https://leetcode.com/problems/binary-tree-cameras/
/// Author : liuyubobobo
/// Time   : 2019-03-18

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


/// Memory Search - Tree DP
/// Using 3 states instead of 4 states (3 states is enough)
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int minCameraCover(TreeNode* root) {

        if(!root) return 0;
        vector<int> res = dfs(root);
        return res[2];
    }

private:
    /// State 0: install a camera
    /// State 1: not install a camera but do not need to be covered
    /// State 2: not install a camera but do need to be covered
    vector<int> dfs(TreeNode* root){

        if(!root) return {0, 0, 0};

        vector<int> lres = dfs(root->left);
        vector<int> rres = dfs(root->right);

        vector<int> res(3);

        res[0] = lres[1] + rres[1];

        res[1] = res[2] = 1 + lres[1] + rres[1];
        res[1] = min(res[1], lres[2] + rres[2]);

        if(root->left)
            res[2] = min(res[2], 1 + lres[0] + rres[2]);
        if(root->right)
            res[2] = min(res[2], 1 + lres[2] + rres[0]);
        if(root->left && root->right)
            res[2] = min(res[2], 2 + lres[0] + rres[0]);

        return res;
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